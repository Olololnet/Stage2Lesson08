#ifndef CSMARTPTR_H
#define CSMARTPTR_H
#include <iostream>

template<typename T>
class CSmartPtr
{
public:
    CSmartPtr();
    CSmartPtr(T* tBase);
    ~CSmartPtr();
    T& operator*();
    T* operator->();

private:
    T* m_pOwner;
    CSmartPtr(const CSmartPtr& cOtherPtr);
    CSmartPtr& operator= (const CSmartPtr& cOtherPtr);
};

template<typename T>
CSmartPtr<T>::CSmartPtr(T* tBase)
:m_pOwner(tBase)
{

}

template<typename T>
CSmartPtr<T>::~CSmartPtr()
{
    delete m_pOwner;
}

template<typename T>
T& CSmartPtr<T>::operator*()
{
    return *m_pOwner;
}

template<typename T>
T* CSmartPtr<T>::operator->()
{
    return m_pOwner;
}

#endif
