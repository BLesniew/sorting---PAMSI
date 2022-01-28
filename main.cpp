#include "./listaJednokierunkowa.h"
#include "./sortableLinkedList.h"
#include<string>
#include<fstream>
#include <time.h>

/*!
Drugie zadanie projektowe na kurs PAMSI - projektowanie algorytmów i metody sztucznej inteligencji,

Wybrano 3 algorytmy sortujace: sortowanie szybkie, sortowanie przez scalanie oraz sortowanie kubelkowe.

Sortowanie kubelkowe zaimplementowano w taki sposob, ze wszystkie dane aby nie tracic czasu nie sa zapisywane
do wspolnej struktury, a od razu przy ich wczytywaniu przydzielane do odpowiednich kubelkow, ktore sa listami jednokierunkowymi

Pozostale dwa algorytmy zaimplementowano na liscie, ktorej kazdemu elementowi dodano pole "key", a wiec
struktura ta przypomina kolejke priorytetowa, z ta roznica, iz sortowanie nie wykonuje sie automatycznie,
a musi byc wywolane odpowiednia metoda quicksort() lub mergesort()
*/

int main()
{
    sortableLinkedList<std::string> movies;
    linkedList<std::string> buckets[10];
    int sum,numberOfData,median,tmpInt,index;
    int numberOfDataToSort;
    std::ifstream data;
    std::ofstream output;

    std::string tmpString,name;

    clock_t start,finish;




    char choice;
    do{
        data.open("dane.csv");
        sum=0, numberOfData=0,median=0,tmpInt=0,index=0;

        std::cout<<"\nWybierz opcje:\n";
        std::cout<<"k - Sortuj filmy kubelkowo\n";
        std::cout<<"s - Sortuj filmy sortowaniem szybkim\n";
        std::cout<<"m - Sortuj filmy sortowaniem przez scalanie\n";
        std::cout<<"q - Wyjdz z aplikacji\n";

        std::cin>>choice;

        switch(choice)
        {
            case 'k':
            output.open("dane_posortowane_.csv");
            getline(data,tmpString);
            output<<tmpString<<"\n";
            std::cout<<"Ile danych posortowac? (Wpisz liczbe ujemna aby posortowac wszystkie dane)\n";
            std::cin>>numberOfDataToSort;

            start = clock();
            while(data.good()&&(index<numberOfDataToSort||numberOfDataToSort<0))
            {
                getline(data,tmpString);

                if(tmpString[tmpString.length()-1]==',')
                {

                }
                else if(tmpString[tmpString.length()-3]=='0')
                {
                    name = tmpString.substr(0,tmpString.length()-5);
                    buckets[9].addOnFront(name);

                    sum+=10;
                    numberOfData++;
                }
                else
                {
                    name = tmpString.substr(0,tmpString.length()-4);
                    tmpInt = (int)tmpString[tmpString.length()-3] - '1';
                    buckets[tmpInt].addOnFront(name);

                    sum=sum+tmpInt+1;
                    numberOfData++;
                }
                index++;
            }

            finish = clock();


            tmpInt=0;
            std::cout<<"Dane posortowane, czas sortowania:"<<double(finish-start)/CLOCKS_PER_SEC<<"s\n";

            for(int i=0;i<10;i++)
            {

                while(!buckets[i].isEmpty())
                {
                    tmpInt++;
                    if(numberOfData%2==1)
                    {
                        if(numberOfData/2+1==tmpInt)
                        {
                            std::cout<<"mediana:"<<i+1<<"\n";
                        }
                    }
                    else
                    {
                        if(numberOfData/2==tmpInt)
                        {
                            median=i+1;
                        }
                        if(numberOfData/2+1==tmpInt)
                        {
                            std::cout<<"mediana:"<<1.0*(median+i+1)/2<<"\n";
                        }

                    }

                    output<<buckets[i].removeFront()<<","<<i+1<<".0"<<"\n";
                }
            }
            std::cout<<"srednia:"<<1.0*sum/numberOfData<<"\n";
            std::cout<<"Dane zapisane do pliku\n";
            break;

            case 's':
            output.open("dane_posortowane_.csv");
            getline(data,tmpString);
            output<<tmpString<<"\n";
            std::cout<<"Ile danych posortowac? (Wpisz liczbe ujemna aby posortowac wszystkie dane)\n";
            std::cin>>numberOfDataToSort;

            while(data.good()&&(index<numberOfDataToSort||numberOfDataToSort<0))
            {
                getline(data,tmpString);

                if(tmpString[tmpString.length()-1]==',')
                {

                }
                else if(tmpString[tmpString.length()-3]=='0')
                {
                    name = tmpString.substr(0,tmpString.length()-5);
                    movies.addOnFront(name,10);
                    numberOfData++;
                    sum+=10;
                }
                else
                {
                    tmpInt = (int)tmpString[tmpString.length()-3] - '0';
                    name = tmpString.substr(0,tmpString.length()-4);
                    movies.addOnFront(name,tmpInt);
                    numberOfData++;
                    sum=sum+tmpInt;
                }
                index++;
            }

            start = clock();
            movies.quicksort();
            finish = clock();
            std::cout<<"Dane posortowane, czas sortowania:"<<double(finish-start)/CLOCKS_PER_SEC<<"s\n";
            std::cout<<"srednia:"<<1.0*sum/numberOfData<<"\n";

            index =0;
            while(!movies.isEmpty())
            {
                index++;
                movies.removeFront(&tmpString,&tmpInt);
                output<<tmpString<<","<<tmpInt<<".0"<<"\n";
                if(numberOfData%2==1)
                {
                    if(index+1==numberOfData/2)
                    {
                        std::cout<<"mediana:"<<tmpInt<<"\n";
                    }
                }
                else
                {
                    if(index==numberOfData/2)
                    {
                        median = tmpInt;
                    }
                    if(index==numberOfData/2+1)
                    {
                        std::cout<<"mediana:"<<(median+tmpInt)/2<<"\n";
                    }
                }

            }
            std::cout<<"Dane zapisane do pliku\n";
            break;

            case 'm':
            output.open("dane_posortowane_.csv");
            getline(data,tmpString);
            output<<tmpString<<"\n";
            std::cout<<"Ile danych posortowac? (Wpisz liczbe ujemna aby posortowac wszystkie dane)\n";
            std::cin>>numberOfDataToSort;

            while(data.good()&&(index<numberOfDataToSort||numberOfDataToSort<0))
            {
                getline(data,tmpString);

                if(tmpString[tmpString.length()-1]==',')
                {

                }
                else if(tmpString[tmpString.length()-3]=='0')
                {
                    name = tmpString.substr(0,tmpString.length()-5);
                    movies.addOnFront(name,10);
                    numberOfData++;
                    sum+=10;
                }
                else
                {
                    tmpInt = (int)tmpString[tmpString.length()-3] - '0';
                    name = tmpString.substr(0,tmpString.length()-4);
                    movies.addOnFront(name,tmpInt);
                    numberOfData++;
                    sum=sum+tmpInt;
                }
                index++;
            }
            start = clock();
            movies.mergesort();
            finish = clock();
            std::cout<<"Dane posortowane, czas sortowania:"<<double(finish-start)/CLOCKS_PER_SEC<<"s\n";
            std::cout<<"srednia:"<<1.0*sum/numberOfData<<"\n";
            index =0;
            while(!movies.isEmpty())
            {
                index++;
                movies.removeFront(&tmpString,&tmpInt);
                output<<tmpString<<","<<tmpInt<<".0"<<"\n";
                if(numberOfData%2==1)
                {
                    if(index+1==numberOfData/2)
                    {
                        std::cout<<"mediana:"<<tmpInt<<"\n";
                    }
                }
                else
                {
                    if(index==numberOfData/2)
                    {
                        median = tmpInt;
                    }
                    if(index==numberOfData/2+1)
                    {
                        std::cout<<"mediana:"<<(median+tmpInt)/2<<"\n";
                    }
                }

            }
            std::cout<<"Dane zapisane do pliku\n";

            break;

            case 'q':
            break;

            default:
            std::cout<<"Nie rozpoznano znaku, sprobuj jeszcze raz\n\n";
            break;

        }
    data.close();
    output.close();
    }while(choice!='q');

return 0;
}
