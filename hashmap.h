#ifndef HASHMAP_H
#define HASHMAP_H
#include "utility.h"
#include "chain.h"

namespace hashmap {

    template <typename T, typename U> 
    class HashMap {
        public:
        virtual U& operator[](const T&) = 0;
        virtual bool exists(const T&) = 0;

        virtual const unsigned int size() const = 0;
        virtual const unsigned int capacity() const = 0;

    };

    /// <summary>Uses Closed Addressing with supporting linking data structure as LinkedList</summary>
    template <typename T, typename U>
    class LinkedHashMap: public HashMap<T, U>{
        private:
            chain::HashChain<T, U> *m_table;
            unsigned int m_capacity;

            void _set(T, U);
            U _get(T) const;

        public:
            LinkedHashMap();
            LinkedHashMap(unsigned int);
            LinkedHashMap(const LinkedHashMap&);

            ~LinkedHashMap();

            U& operator[](const T&);
            bool exists(const T&);

            const unsigned int size() const;
            const unsigned int capacity() const;
    };

    /// <summary>Uses Open Addressing with Linear probing</summary>
    template <typename T, typename U>
    class LinearHashMap: public HashMap<T, U>{
        private:
            node::_HashNode<T, U> *m_table;
            unsigned int m_capacity;

            unsigned int m_linearProbe(T);
            void _set(T, U);
            U _get(T) const;

        public:
            LinearHashMap();
            LinearHashMap(unsigned int);
            LinearHashMap(const LinearHashMap&);

            ~LinearHashMap();

            U& operator[](const T&);
            bool exists(const T&);

            const unsigned int size() const;
            const unsigned int capacity() const;
    };

    /// <summary>Uses Open Addressing with Linear probing</summary>
    template <typename T, typename U>
    class QuadHashMap: public HashMap<T,U>{
        private:
            node::_HashNode<T, U> *m_table;
            unsigned int m_capacity;

            unsigned int m_quadProbe(T);
            void _set(T, U);
            U _get(T) const;

        public:
            QuadHashMap();
            QuadHashMap(unsigned int);
            QuadHashMap(const QuadHashMap&);

            ~QuadHashMap();

            U& operator[](const T&);
            bool exists(const T&);

            const unsigned int size() const;
            const unsigned int capacity() const;
    };
    
} // namespace hashmap

#endif
