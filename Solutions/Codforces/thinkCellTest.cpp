#include <map>
#include "bits/stdc++.h"
using namespace std;
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
		: m_valBegin(val)
	{}

	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

		if (!( keyBegin < keyEnd )) {
			//cout<<"Bad input, not processing the entry";
			return;
		}

		if (m_map.empty()) {
			if (!(val == m_valBegin)) {
				m_map[keyBegin] = val;
			}
			return;
		}
		else {

			//used in multiple places, these are the only 2 log(N) calls being made.
			auto lowerBoundItr = m_map.lower_bound(keyEnd);
			auto lowerBoundItrForKeyBegin = m_map.lower_bound(keyBegin);


			//1) Inserting at the start
			if (!((m_map.begin()->first) < keyBegin)) {
				//make sure map is canonical
				if (val == m_map.begin()->second) {
					m_map.erase(m_map.begin());
					assign(keyBegin, keyEnd, val);
					return;
				}

				m_map[keyBegin] = val;
				if (!(m_map.begin()->first < keyEnd)) {
					return;
				}
				else {
					auto itrBegin = ++(m_map.begin());
					auto itrEnd = (lowerBoundItr == m_map.end()) ? m_map.end() : lowerBoundItr;
					if (itrBegin == itrEnd) {
						return;
					} else {
						V curValue = (*this)[keyEnd];
						m_map.erase(itrBegin, itrEnd);
						if (!(curValue == val)) {
							m_map[keyEnd] = curValue;
						}
					}
					return;
				}
			}

			//2) Inserting at the end
			auto itrToLastKey = --(m_map.end());

			if ((((itrToLastKey)->first) < keyBegin)) {
				//make sure map is canonical
				if (val == (itrToLastKey)->second) {
					//already present due to interval nature. so ignore this update.
					return;
				}

				m_map[keyBegin] = val;
				return;
			}

			//3) Inserting in between(not first/last entry on map)

			//3a If keyBegin already exists in m_map
			auto search = lowerBoundItrForKeyBegin;
			if (search != m_map.end() and search->first == keyBegin) {

				auto itrBegin = search++;
				auto itrEnd = (lowerBoundItr == m_map.end()) ? m_map.end() : lowerBoundItr;
				if (itrBegin == itrEnd) {
					m_map[keyBegin] = val;
					return;
				} else {
					V curValue = (*this)[keyEnd];
					m_map.erase(itrBegin, itrEnd);
					if (!(curValue == val)) {
						m_map[keyEnd] = curValue;
					}
				}
				m_map[keyBegin] = val;
				return;
			}

			//3b KeyBegin doesnt exist in Map, insert in middle.
			auto itrLowerBound = --(m_map.lower_bound(keyBegin));
			//make sure map is canonical
			if ((itrLowerBound)->second ==  val) {
				auto itrBegin = ++(itrLowerBound);
				auto itrEnd = (lowerBoundItr == m_map.end()) ? m_map.end() : lowerBoundItr;
				if (itrBegin == itrEnd) {
					return;
				} else {
					V curValue = (*this)[keyEnd];
					m_map.erase(itrBegin, itrEnd);
					if (!( curValue == val)) {
						m_map[keyEnd] = curValue;
					}
				}
				return;
			}
			else {
				auto itrBegin = ++(itrLowerBound);
				auto itrEnd = (lowerBoundItr == m_map.end()) ? m_map.end() : lowerBoundItr;


				//3ba no deletion, insertion in bn 2 intervals case
				auto itrNext = lowerBoundItrForKeyBegin;
				auto itrPrev = --(lowerBoundItrForKeyBegin);
				if ((itrPrev->first < keyBegin)  and (!(itrNext->first < keyEnd ))) {
					V oldValue = (*this)[keyEnd];

					if (!(itrPrev->second == val))
						m_map[keyBegin] = val;

					if (itrNext->second != oldValue) {
						m_map.erase(itrNext);
						m_map[keyEnd] = oldValue;
					}
					return;
				}

				//3bb insertion between 2 intervals
				if (itrBegin == itrEnd) {
					return;
				} else {
					V curValue = (*this)[keyEnd];
					m_map.erase(itrBegin, itrEnd);
					if (!(curValue == val)) {
						m_map[keyEnd] = curValue;
					}
				}


				if (!((*this)[keyBegin] == val)) {
					m_map[keyBegin] = val;
				}
				return;
			}
		}
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

	void test() {
		const int numTests = 100000;
		for (int i = 0; i < numTests; ++i) {
			// Generate random keys and value
			int keyBegin = std::rand() % 100;
			int keyEnd = keyBegin + std::rand() % 50;
			char val = 'A' + std::rand() % 26;
			//cout << keyBegin << " " << keyEnd << " " << val << endl;
			assign(keyBegin, keyEnd, val);

			for (int key = keyBegin; key < keyEnd; ++key) {
				if ((*this)[key] != val) {
					cout << "NOT OKAY" << endl;
				}
			}
			//for (auto i : m_map) cerr << i.first << " " << i.second << endl;
		}
	}
};
int main() {

	interval_map<int, char> myMap('A');

	myMap.test();

	return 0;
}
