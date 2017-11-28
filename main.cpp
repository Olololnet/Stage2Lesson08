#include <iostream>
#include "csmartptr.h"
#include <limits>
#include "assert.h"

struct CIntStruct
{
    int m_iData;
    CIntStruct(int iData) : m_iData(iData){}
    void ShowData()
    {
        std::cout << m_iData << std::endl;
    }
};

template<typename T>
struct CTypeStruct
{
    T m_pData;
    CTypeStruct(T tData) : m_pData(tData){}
    void ShowData()
    {
        std::cout << m_pData << std::endl;
    }
};

void Exercise4()
{
    // Exercise4: реализовать класс умного указателя
    // CSmartPtr<CIntStruct> ptr(new CIntStruct(123))
    // реализация *ptr; ptr->ShowData, сравнение указателя на 0

    CSmartPtr<CIntStruct> cSmartPtrToIntStruct(new CIntStruct(2));

    cSmartPtrToIntStruct->ShowData();
    CIntStruct cNewStruct(777);
    *cSmartPtrToIntStruct = cNewStruct;
    cSmartPtrToIntStruct->ShowData();

    CSmartPtr<int> cSmartPtrToInt(new int(3));
    *cSmartPtrToInt = 100;
    std::cout << *cSmartPtrToInt << std::endl;

    CSmartPtr<CTypeStruct<double> > cSmartPtrToTemplateDouble(new CTypeStruct<double>(2.));
    CTypeStruct<double> ctsTempStruct(175000.);
    *cSmartPtrToTemplateDouble = ctsTempStruct;
    cSmartPtrToTemplateDouble->ShowData();
}

template <typename T>
void CustomSwap (T& tFirstValue, T& tSecondValue)
{
    T tFirstCopy(tFirstValue);
    tFirstValue  = tSecondValue;
    tSecondValue = tFirstCopy;
}

template<typename T>
struct CustomPair
{
    T tMin;
    T tMax;

    void ShowElements()
    {
        std::cout << "Min: " << tMin << " max: " << tMax << std::endl;
    }
};

template<typename T>
CustomPair<T> FindMinMax(T* tStart, T* tEnd)
{
    CustomPair<T> cPair;

    if (tEnd < tStart)
        CustomSwap(tStart, tEnd);

    if (tStart == tEnd)
    {
        cPair.tMin = cPair.tMax = *tStart;
        return cPair;
    }

    cPair.tMin = std::numeric_limits<T>::max();
    cPair.tMax = std::numeric_limits<T>::min();

    while (tStart < tEnd)
    {
        if (*tStart > cPair.tMax)
            cPair.tMax = *tStart;
        if (*tStart < cPair.tMin)
            cPair.tMin = *tStart;
        ++tStart;
    }

    return cPair;
}

void Exercise3()
{
    // Exercise3: в заданной итераторами последовательности найти пару чисел,
    // которые являются минимальным и максимальным значением

    int    szIntsArray[]    = {9, 2, 3, 4, 5, 6, 7};
    int    iIntsCount       = sizeof(szIntsArray)/sizeof(szIntsArray[0]);
    double szDoublesArray[] = {9.1, 2.2, 3.6, 4.1, 5.9, 6., 7.1};
    int    iDoublesCount    = sizeof(szDoublesArray)/sizeof(szDoublesArray[0]);

    FindMinMax(szIntsArray,    szIntsArray    + iIntsCount).ShowElements();
    FindMinMax(szDoublesArray, szDoublesArray + iDoublesCount).ShowElements();
}

template<typename T>
T GetArithmeticMean(T* pStart, T* pEnd)
{
    T tElementsNumber(0);
    T tSumOfElements (0);
    T tArithmeticMean(0);

    if (pStart > pEnd)
        CustomSwap(pStart, pEnd);

    while (pStart < pEnd)
    {
        tSumOfElements += *pStart++;
        ++tElementsNumber;
    }

    tArithmeticMean = tSumOfElements / tElementsNumber;
    return tArithmeticMean;
}

void Exercise2()
{
    // Exercise2: написать функцию нахождения среднего арифметического в массиве

    int    szIntsArray[]    = {9, 2, 3, 4, 5, 6, 7};
    int    iIntsCount       = sizeof(szIntsArray)/sizeof(szIntsArray[0]);
    double szDoublesArray[] = {9.1, 2.2, 3.6, 4.1, 5.9, 6., 7.1};
    int    iDoublesCount    = sizeof(szDoublesArray)/sizeof(szDoublesArray[0]);

    std::cout << GetArithmeticMean(szIntsArray,    szIntsArray    + iIntsCount)    << std::endl;
    std::cout << GetArithmeticMean(szDoublesArray, szDoublesArray + iDoublesCount) << std::endl;
}

template<typename T>
void reverse(T* pValue)
{
    T tValueCopy(*pValue);
    T tConstructedIntegral(0);

    while (tValueCopy)
    {
        tConstructedIntegral = tConstructedIntegral*10 + tValueCopy%10;
        tValueCopy /= 10;
    }

    *pValue = tConstructedIntegral;
}

template<>
void reverse(char* tStartValue)
{
    char* tStartCopy = tStartValue;
    char* tEndValue  = NULL;
    const char chEnd = '\0';

    while (*tStartCopy != chEnd)
        ++tStartCopy;

    tEndValue = tStartCopy;

    while (tStartValue < --tEndValue)
        CustomSwap(*tStartValue++, *tEndValue);
}

template<>
void reverse(double*)
{
    assert(std::numeric_limits<double>::is_integer);
}

template<>
void reverse(float*)
{
    assert(std::numeric_limits<float>::is_integer);
}

void Exercise1()
{
    // Exercise1: написать функцию переворота числа (строки)
    // вид функции void reverse(T* tStartValue);

    char chString[] = "string";
    reverse(chString);
    std::cout << chString << std::endl;

    float iIntValue = 123456;
    reverse(&iIntValue);
    std::cout << iIntValue << std::endl;
}

int main()
{

//    Exercise4();
//    Exercise3();
//    Exercise2();
//    Exercise1();

    return 0;
}
