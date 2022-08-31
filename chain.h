#ifndef CHAIN_H
#define CHAIN_H
#include "utility.h"

namespace hashmap{

    namespace chain
    {
        /// <summary></summmary>
        template <typename T, typename U>
        class HashChain{
            private:
                node::_HashChainNode<T,U> *m_head;
                node::_HashChainNode<T,U> *m_tail;
                unsigned int m_size;

            public:
                HashChain();

                node::_HashChainNode<T,U>* getHead() const;
                node::_HashChainNode<T,U>* getTail() const;

                void push_back(T, U);
                void push_front(T, U);

                void pop_back();
                void pop_front();

                node::_HashChainNode<T,U> front() const;
                node::_HashChainNode<T,U> back() const;

        };
        
    } // namespace chain


} // namespace hashmap

#endif