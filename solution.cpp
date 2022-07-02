/* #define spacefirst */
/* #define after */
/* #define spaceoutput */ 

class LRUCache : Cache {
    
    public:
    LRUCache(int capacity) {
        this->cp = capacity;
#ifdef spacefirst //create fist blank line
				cout << endl;
#endif
    }
    
    void set(int key, int value) {
			Node* cur = tail;
#ifdef spaceoutput //create blank line for every set
				cout << endl;
#endif

        if ( mp.size() >= cp ) {
			/* cout << "list full" << endl; */
            mp.erase(tail->key);
            
            Node* new_tail = tail->next;
            new_tail->prev = nullptr; 
						tail = new_tail;
        }
				

		Node* node =  new Node(key, value);
	
		if ( mp.size() == 0 ) {
			/* cout << "list empty" << endl; */
			tail = head = node;
			mp.insert(pair<int, Node*>(key, node));
			goto done;
			/* return; */
		}

		if ( mp.count(key) == 0) {
			/* cout << "key not in map";// << endl; */

			node->prev = head;
			head->next = node;
			head = node; 

			mp.insert(pair<int, Node*>(key, node));
			goto done;
			/* return; */
		} else {

#ifdef before //for debugging
			cout << "mp.size()= " << mp.size() << ". Before-" ;
			while ( cur != nullptr ) {
				cout << cur->key << ":" << cur->value << ",";
				cur = cur->next;
			}
			cout << endl;
#endif

			Node* new_head; 
			Node* neigh_next; 
			Node* neigh_prev;

			new_head = mp[key];
			new_head->value = value; // forgot this line 2nd
			/* cout<<"newhead "<<new_head->key << "->" << new_head->value << endl; */
			if (new_head != head) {
				/* cout << "newhead not head" << endl; */
				neigh_next = new_head->next;
			} else {
				/* cout << "newhead is head" << endl; */
				// nothing more to do
				goto done;
				/* return; */
			}
			if (new_head != tail) {
				/* cout << "newhead not tail" << endl; */
				neigh_prev = new_head->prev;
				neigh_next->prev = neigh_prev;
				neigh_prev->next = neigh_next;
			} else {
				/* cout << "newhead is tail" << endl; */
				neigh_next->prev = nullptr;
				tail = neigh_next;
			}

			new_head->next = nullptr;
			new_head->prev = head;
			head->next = new_head; // forgot this line 1st
			head = new_head;
		}
				
		done:
#ifdef after //for debugging
		cur = tail;
		while ( cur != nullptr ) {
			cout << cur->key << ":" << cur->value << ",";
			cur = cur->next;
		}
		cout << endl;
#endif
		return;
    }
    
    int get(int key) {
        if ( mp.count(key) < 1 ) {
            return -1;
        }
		int value = mp[key]->value;
		/* this->set(key,value); //refresh cache */
        return value;
    }
};
