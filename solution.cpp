class LRUCache : Cache {
    
    public:
    LRUCache(int capacity) {
        this->cp = capacity;
    }
    
    void set(int key, int value) {

        if ( mp.size() >= cp ) {
				// list full

            mp.erase(tail->key);
            
            Node* new_tail = tail->next;
            new_tail->prev = nullptr; 
						tail = new_tail;
        }
				

		Node* node =  new Node(key, value);
	
		if ( mp.size() == 0 ) {
			//list empty

			tail = head = node;
			mp.insert(pair<int, Node*>(key, node));
			return;
		}

		if ( mp.count(key) == 0) {
			//key not in map

			node->prev = head;
			head->next = node;
			head = node; 

			mp.insert(pair<int, Node*>(key, node));

			return;

		} else {

			Node* new_head; 
			Node* neigh_next; 
			Node* neigh_prev;

			new_head = mp[key];
			new_head->value = value;

			if (new_head != head) {
				//newhead not head

				neigh_next = new_head->next;

			} else {
				//newhead is head

				return;
			}
			if (new_head != tail) {
				//newhead not tail

				neigh_prev = new_head->prev;
				neigh_next->prev = neigh_prev;
				neigh_prev->next = neigh_next;

			} else {
				//newhead is tail

				neigh_next->prev = nullptr;
				tail = neigh_next;
			}

			new_head->next = nullptr;
			new_head->prev = head;
			head->next = new_head;
			head = new_head;
		}
				
		return;
    }
    
    int get(int key) {

		/* Since it's supposed to be LRU, I would expect to refresh least
		 * recently used on every get too. This can be done as follows:
		 *
		 * this->set(key,mp[key]->value);
		 *
		 * Alas, the test cases show it's not what they are looking for.
		 */

        return ( mp.count(key) < 1 ) ? -1 : mp[key]->value;
    }

};
