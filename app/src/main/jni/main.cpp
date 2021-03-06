/* DO NOT EDIT THIS FILE - it is machine generated */

#include "com_example_stereotype13_jsonreader_MainActivity.h"
/* Header for class com_example_stereotype13_jsonreader_MainActivity */


/*
 * Class:     com_example_stereotype13_jsonreader_MainActivity
 * Method:    isPrime
 * Signature: (I)Z
 */
#include <list>
#include <memory>
#include <algorithm>

using namespace std;

shared_ptr<list<unsigned long long int>> getPrimeList(unsigned long int nPrimes) {
  auto pPrimeList = make_shared<list<unsigned long long int>>();

  pPrimeList->push_back(2);
  pPrimeList->push_back(3);

  unsigned long long int testInt = 5;
  unsigned long long int testIntOverTwo;
  bool isPrime = true;
  unsigned long int primesFound = 2;

  while(primesFound < nPrimes) {

    testIntOverTwo = testInt / 2;

    for(const auto& n : *pPrimeList) {

      if(n > testIntOverTwo)
        break;

      if(!(testInt % n)) {
        isPrime = false;
        break;
      }

    }

    if(isPrime) {
      pPrimeList->push_back(testInt);
      ++primesFound;
    }

    isPrime = true;
    ++testInt;

  }

  return pPrimeList;
}


bool prime(const shared_ptr<list<unsigned long long int>> pPrimeList, const unsigned long long int testNumber) {
  return binary_search(pPrimeList->begin(), pPrimeList->end(), testNumber);
}

JNIEXPORT jboolean JNICALL Java_com_example_stereotype13_jsonreader_MainActivity_isPrime
  (JNIEnv *env, jobject obj, jint n) {
    auto pPrimeList = getPrimeList(10000);
    return prime(pPrimeList, n);
  }

