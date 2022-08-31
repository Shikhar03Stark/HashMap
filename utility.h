#ifndef UTILITY_H
#define UTILITY_H

namespace hashmap {
    namespace algo{
        template <typename T>
        unsigned int _hash_4byte(T value, unsigned int capacity){
            unsigned int aux = *((unsigned int *)(void *)&value);
            aux = (aux+(aux<<1));
            aux %= capacity;
            aux = (aux+(aux<<1));
            aux %= capacity;

            return (unsigned int)aux;
        }

        template <typename T>
        unsigned int _hash_8byte(T value, unsigned int capacity){
            unsigned long long aux = *((unsigned long long *)(void *)&value);
            aux = (aux+(aux<<1));
            aux %= (unsigned long long)capacity;
            aux = (aux+(aux<<1));
            aux %= (unsigned long long)capacity;
            aux = (aux+(aux<<1));
            aux %= (unsigned long long)capacity;
            aux = (aux+(aux<<1));
            aux %= (unsigned long long)capacity;

            return (unsigned int)aux;
        }

        template <typename T>
        unsigned int _hash_ptr(T *value, unsigned int capacity){
            unsigned long long aux = *((unsigned long long *)(void *)value);
            aux = (aux+(aux<<1));
            aux %= (unsigned long long)capacity;
            aux = (aux+(aux<<1));
            aux %= (unsigned long long)capacity;
            aux = (aux+(aux<<1));
            aux %= (unsigned long long)capacity;
            aux = (aux+(aux<<1));
            aux %= (unsigned long long)capacity;

            return (unsigned int)aux;
        }

        unsigned int _hash_str(char *s, unsigned int n, unsigned int capacity){
            unsigned int primes[90] = {
                656561, 656587,	656597,	656599,	656603,	656609,	656651,	656657,	656671,	656681,
                656683,	656687,	656701,	656707,	656737,	656741,	656749,	656753,	656771,	656783,
                656791,	656809,	656819,	656833,	656839,	656891,	656917,	656923,	656939,	656951,
                656959,	656977,	656989,	656993,	657017,	657029,	657047,	657049,	657061,	657071,
                657079,	657089,	657091,	657113,	657121,	657127,	657131,	657187,	657193,	657197,
                657233,	657257,	657269,	657281,	657289,	657299,	657311,	657313,	657323,	657347,
                657361,	657383,	657403,	657413,	657431,	657439,	657451,	657469,	657473,	657491,
                657493,	657497,	657499,	657523,	657529,	657539,	657557,	657581,	657583,	657589,
                657607,	657617,	657649,	657653,	657659,	657661,	657703,	657707,	657719,	657743};

            unsigned int hash = 0;
            for(unsigned int i = 0, p = 0; i<n; i++){
                unsigned int next = (p+1)%90;
                hash += (s[i]*p + next)%capacity;
                p = (p+1)%90;
            }

            return hash;
        }

    }

    namespace node{
        template <typename T, typename U>
        class _HashChainNode{
            private:
                T m_key;
                U m_value;
                _HashChainNode<T, U> *m_next;
                _HashChainNode<T, U> *m_prev;

            public:
                _HashChainNode(T, U);

                void setValue(const U &);
                U getValue() const;

                _HashChainNode<T,U>* next() const;
                void setNext(_HashChainNode *);

                _HashChainNode<T,U>* prev() const;
                void setPrev(_HashChainNode *);
        };

        template<typename T, typename U>
        class _HashNode{
            private:
                T m_key;
                U m_val;
                bool set;

            public:
                _HashNode(T, U);

                void setValue(const U &);
                U getValue() const;
        };

    } // namespace node
    
} // namespace hashmap

#endif
