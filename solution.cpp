class LRUCache : Cache {
    
    public:
    LRUCache(int capacity) {
        this->cp = capacity;
    }
    
    void set(int key, int value) {
        Node* node =  new Node(key, value);
    
        // the list is empty
        if ( mp.size() == 0 ) {
            cout << "list is empty, adding first item " << key << "->" << value << "\n";
            tail = head = node;
            mp.insert(pair<int, Node*>(key, node));
            return;
        }
        
        
        cout << "map size is " << mp.size() << "/" << cp << "\n" ;

        // the list is full
        if ( mp.size() >= cp ) {
            cout << "list is full ";

            Node* prev_node = tail->prev;
            cout << "dropping item " << tail->key << "->" << tail->value << "\n";
            prev_node->next = nullptr;
            
            mp.erase(key);
            
            prev_node->next = node;
            node->prev = prev_node;
            cout << "adding first item " << key << "->" << value << "\n";
            mp.insert(pair<int, Node*>(key, node));
            return;
        } else {
            // the list is not full
            cout << "adding item to the tail " << key << "->" << value << "\n";

            tail->next = node;
            // cout << "node->prev = tail\n";

            node->prev = tail;
            // cout << "mp.insert\n";
            mp.insert(pair<int, Node*>(key, node));
            
            // cout << "end set\n";
            return;
        }
        
    }
    
    int get(int key) {
        if ( mp.count(key) < 1 ) {
            return -1;
        }
        return mp[key]->value;
    }
};
