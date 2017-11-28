#ifndef CSMARTPTR_H
#define CSMARTPTR_H

template<typename T>
class CSmartPtr
{
public:
    CSmartPtr();
    CSmartPtr(T* tBase);
    ~CSmartPtr();
    T& operator*();
    T* operator->();
    operator bool() const;

private:
    T* m_pOwner;
    CSmartPtr(const CSmartPtr& cOtherPtr);
    CSmartPtr& operator= (const CSmartPtr& cOtherPtr);
};

template<typename T>
CSmartPtr<T>::CSmartPtr()
:m_pOwner(0)
{

}

template<typename T>
CSmartPtr<T>::CSmartPtr(T* tBase)
:m_pOwner(tBase)
{

}

template<typename T>
CSmartPtr<T>::~CSmartPtr()
{
    if (m_pOwner)
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

template<typename T>
CSmartPtr<T>::operator bool() const
{
    return (m_pOwner) ? true : false;
}

#endif
