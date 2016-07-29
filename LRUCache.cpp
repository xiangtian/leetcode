#include <iostream>
#include <map>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        mCapacity = capacity;
        mHead = NULL;
    }

    int get(int key) {
        map<int,DulNode*>::iterator it = mCache.find(key);
        if(it == mCache.end()) {
            return -1;
        }

        // move cur node to Head
        DulNode* cur = it->second;
        moveToHead(cur);
        return cur->val;
    }

    void set(int key, int value) {
        map<int,DulNode*>::iterator it = mCache.find(key);
        // change val in cache
        if(it != mCache.end()) {
            it->second->val = value;
            moveToHead(it->second);
        }
        else if (mCache.size() < mCapacity)
        {
            insertCache(key, value);
        }
        else
        {
            DulNode* tail = mHead->prior;
            if(mHead == tail) // for capacity is 1
            {
                mCache.erase(mCache.find(tail->key));
                delete tail;
                mHead = NULL;
            }
            else
            {
                mCache.erase(mCache.find(tail->key));
                tail->prior->next = mHead;
                mHead->prior = tail->prior;
                delete tail;
            }
            insertCache(key, value);
        }
    }

private:
    struct DulNode {
        int key;
        int val;
        DulNode* prior;
        DulNode* next;
        DulNode(int x, int y):key(x),val(y),prior(NULL),next(NULL){}
    };

    void moveToHead(DulNode* cur)
    {
        if(cur == mHead)
        {
            return;
        }

        if(cur->next != NULL && cur->prior != NULL)
        {
            cur->prior->next = cur->next;
            cur->next->prior = cur->prior;
        }

        mHead->prior->next = cur;
        cur->prior = mHead->prior;
        cur->next = mHead;
        mHead->prior = cur;
        mHead = cur;
    }

    void insertCache(int key, int val)
    {
        DulNode* cur = new DulNode(key, val);
        mCache[key] = cur;
        if(mCache.size() == 1) {
            cur->next = cur;
            cur->prior = cur;
            mHead = cur;
        }
        else
        {
            moveToHead(cur);
        }
    }


private:
    map<int, DulNode*> mCache;
    int mCapacity;
    DulNode* mHead;
};

int main(void)
{
    LRUCache cache(3);
    cache.set(1,1);
    cache.set(2,2);
    cache.set(3,3); // 3, 2, 1
    cout << cache.get(1) << endl; // 1, 3, 2
    cache.set(4,4); // 4, 1, 3
    cout << cache.get(1) << endl; // 1 4 3
    cout << cache.get(3) << endl; // 3 1 4
    cout << cache.get(2) << endl;
    cache.set(5, 5); // 5 3 1
    cout << cache.get(1) << endl; // 1 5 3
    cout << cache.get(2) << endl; // 1 5 3
    cout << cache.get(3) << endl; // 3 1 5
    cout << cache.get(4) << endl; // 3 1 5
    cout << cache.get(5) << endl; // 5 3 1
    cache.set(1, 6);
    cout << cache.get(1) << endl;

    LRUCache cache2(1);
    cache2.set(1, 1);
    cout << cache2.get(1) << endl;
    cout << cache2.get(2) << endl;
    cache2.set(2, 2);
    cout << cache2.get(2) << endl;
}
