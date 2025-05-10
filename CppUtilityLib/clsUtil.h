#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


class clsUtil
{
public:

    enum enPrimeOrNotPrime
    {
        Prime = 1,
        NotPrime = 2
    };

    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4,
    };

    static int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case CapitalLetter:
            return char(RandomNumber(65, 90));
        case SmallLetter:
            return char(RandomNumber(97, 122));
        case SpecialCharacter:
            return char(RandomNumber(33, 47));
        case Digit:
            return char(RandomNumber(48, 57));
        default:
            return ' ';
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;
        for (int i = 0; i < Length; i++)
            Word += GetRandomCharacter(CharType);
        return Word;
    }

    static string GenerateKey()
    {
        string Key;
        Key = GenerateWord(CapitalLetter, 4) + "-";
        Key += GenerateWord(CapitalLetter, 4) + "-";
        Key += GenerateWord(CapitalLetter, 4) + "-";
        Key += GenerateWord(CapitalLetter, 4);
        return Key;
    }

    static void ReadArray(int arr[100], short& Length)
    {
        for (int i = 0; i < Length; i++)
        {
            cout << "\nElement[" << i + 1 << "]: ";
            cin >> arr[i];
        }
    }

    static void PrintArray(int arr[100], short Length)
    {
        for (int i = 0; i < Length; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    static int TimesRepeated(int Number, int arr[100], short Length)
    {
        int Count = 0;
        for (int i = 0; i < Length; i++)
            if (Number == arr[i])
                Count++;
        return Count;
    }

    static void FillArrayWithRandomNumbers(int arr[100], short& Length)
    {
        cout << "\nEnter Number of Elements:\n";
        cin >> Length;
        for (int i = 0; i < Length; i++)
            arr[i] = RandomNumber(1, 100);
    }

    static int MaxNumberInArray(int arr[100], short Length)
    {
        int Max = arr[0];
        for (int i = 1; i < Length; i++)
            if (arr[i] > Max)
                Max = arr[i];
        return Max;
    }

    static int MinNumberInArray(int arr[100], short Length)
    {
        int Min = arr[0];
        for (int i = 1; i < Length; i++)
            if (arr[i] < Min)
                Min = arr[i];
        return Min;
    }

    static int SumArray(int arr[100], int Length)
    {
        int Sum = 0;
        for (int i = 0; i < Length; i++)
            Sum += arr[i];
        return Sum;
    }

    static float ArrayAverage(int arr[100], int Length)
    {
        return static_cast<float>(SumArray(arr, Length)) / Length;
    }

    static void CopyArray(int arrSource[100], int arrDestination[100], int Length)
    {
        for (int i = 0; i < Length; i++)
            arrDestination[i] = arrSource[i];
    }

    static enPrimeOrNotPrime CheckPrime(int Number)
    {
        if (Number <= 1)
            return NotPrime;
        for (int i = 2; i <= sqrt(Number); i++)
            if (Number % i == 0)
                return NotPrime;
        return Prime;
    }

    static void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], short Length1, short& Length2)
    {
        Length2 = 0;
        for (int i = 0; i < Length1; i++)
        {
            if (CheckPrime(arrSource[i]) == Prime)
                arrDestination[Length2++] = arrSource[i];
        }
    }

    static void SumOfArrays(int arr1[100], int arr2[100], int arrSum[100], int Length)
    {
        for (int i = 0; i < Length; i++)
            arrSum[i] = arr1[i] + arr2[i];
    }

    static void FillArrayWith1ToN(int arr[100], short Length)
    {
        for (int i = 0; i < Length; i++)
            arr[i] = i + 1;
    }

    static void Swap(int& Value1, int& Value2)
    {
        int Temp = Value1;
        Value1 = Value2;
        Value2 = Temp;
    }

    static void ShuffleArray(int arr[100], short Length)
    {
        for (int i = 0; i < Length; i++)
            Swap(arr[RandomNumber(0, Length - 1)], arr[RandomNumber(0, Length - 1)]);
    }

    static void CopyArrayInReverse(int arr1[100], int arr2[100], short Length)
    {
        for (int i = 0; i < Length; i++)
            arr1[i] = arr2[Length - 1 - i];
    }

    static void FillArrayWithKeys(string arr[100], short Length)
    {
        for (int i = 0; i < Length; i++)
            arr[i] = GenerateKey();
    }

    static void PrintStringArray(string arr[100], short Length)
    {
        for (int i = 0; i < Length; i++)
            cout << "Array[" << i << "] : " << arr[i] << endl;
    }

    static short FindNumberPositionInArray(int Number, int arr[100], short Length)
    {
        for (int i = 0; i < Length; i++)
            if (arr[i] == Number)
                return i;
        return -1;
    }

    static bool IsNumberInArray(int Number, int arr[100], short Length)
    {
        return FindNumberPositionInArray(Number, arr, Length) != -1;
    }

    static void AddArrayElement(int Number, int arr[100], short& Length)
    {
        arr[Length++] = Number;
    }

    static int ReadNumber()
    {
        int Number;
        cout << "\nEnter a Number? ";
        cin >> Number;
        return Number;
    }

    static void InputUserNumberInArray(int arr[100], short& Length)
    {
        bool AddMore = true;
        do
        {
            AddArrayElement(ReadNumber(), arr, Length);
            cout << "\nDo you want to add more number 0/1? ";
            cin >> AddMore;
        } while (AddMore);
    }

    static void CopyArrayUsingAddArrayElement(int SArr[100], int DArr[100], short SLength, short& DLength)
    {
        for (int i = 0; i < SLength; i++)
            AddArrayElement(SArr[i], DArr, DLength);
    }

    static bool IsOddNumber(int Number)
    {
        return Number % 2 != 0;
    }

    static bool IsEvenNumber(int Number)
    {
        return Number % 2 == 0;
    }

    static void CopyOddNumbers(int SArr[100], int DArr[100], short SLength, short& DLength)
    {
        for (int i = 0; i < SLength; i++)
            if (IsOddNumber(SArr[i]))
                AddArrayElement(SArr[i], DArr, DLength);
    }

    static void CopyPrimeNumbers(int SArr[100], int DArr[100], short SLength, short& DLength)
    {
        for (int i = 0; i < SLength; i++)
            if (CheckPrime(SArr[i]) == Prime)
                AddArrayElement(SArr[i], DArr, DLength);
    }

    static void FillArray(int arr[100], int& Length)
    {
        Length = 2;
        arr[0] = 33;
        arr[1] = 44;
    }

    static void CopyDistinctNumberToArray(int SArr[100], int DArr[100], short SLength, short& DLength)
    {
        for (int i = 0; i < SLength; i++)
            if (!IsNumberInArray(SArr[i], DArr, DLength))
                AddArrayElement(SArr[i], DArr, DLength);
    }

    static bool IsPalindromeArray(int arr[100], short Length)
    {
        for (int i = 0; i < Length / 2; i++)
            if (arr[i] != arr[Length - i - 1])
                return false;
        return true;
    }

    static short OddCount(int arr[100], short Length)
    {
        short Count = 0;
        for (int i = 0; i < Length; i++)
            if (IsOddNumber(arr[i]))
                Count++;
        return Count;
    }
};