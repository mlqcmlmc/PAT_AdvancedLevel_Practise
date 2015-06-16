#include<iostream>
#include<vector>
#include<algorithm>
#include "stdio.h"
using namespace std;
struct Term
{
    int exponents;
    double coefficients;
};
struct Polynomial
{
    int trem_number;
    vector<Term> all_term;
};

Polynomial PolynomialMultiple(const Polynomial poly1, const Polynomial poly2)
{
    Polynomial poly12;
    Term temp_term;
    double term_multiple[2002] = { 0.0 };
    int index = 0;
    for (int i = 0; i < poly1.all_term.size(); i++)
    {
        for (int j = 0; j < poly2.all_term.size(); j++)
        {
            index = poly1.all_term[i].exponents + poly2.all_term[j].exponents;
            term_multiple[index] += poly1.all_term[i].coefficients*poly2.all_term[j].coefficients;
        }
    }
    for (int i = 2001; i >= 0; i--)
    {
        if (abs(term_multiple[i]) >= 10e-5)
        {
            temp_term.exponents = i;
            temp_term.coefficients = term_multiple[i];
            poly12.all_term.push_back(temp_term);
        }
    }
    poly12.trem_number = poly12.all_term.size();
    return poly12;
}

int main()
{
    Polynomial poly1, poly2, poly12;
    Term temp_term;
    cin >> poly1.trem_number;
    for (int i = 0; i < poly1.trem_number; i++)
    {
        cin >> temp_term.exponents >> temp_term.coefficients;
        poly1.all_term.push_back(temp_term);
    }
    cin >> poly2.trem_number;
    for (int i = 0; i < poly2.trem_number; i++)
    {
        cin >> temp_term.exponents >> temp_term.coefficients;
        poly2.all_term.push_back(temp_term);
    }
    poly12 = PolynomialMultiple(poly1, poly2);
    cout << poly12.trem_number ;
    for (int i = 0; i < poly12.trem_number; i++)
    {
        printf(" %d %.1f", poly12.all_term[i].exponents, poly12.all_term[i].coefficients);
        //cout << ' ' << poly12.all_term[i].exponents << ' ' << poly12.all_term[i].coefficients;
    }
    cout << endl;
    return 0;
}

