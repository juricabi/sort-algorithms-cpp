#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <stack> 
#include <math.h>


void BubbleSort1( int *num, int lenght)
{
	using namespace std;
	int bilozamjena = 1;
	for(int i = 0; i < lenght && bilozamjena == 1; i++)
	{
		for(int j=0 ; j< lenght -1 -i; j++)
		{
			bilozamjena = 0;
			if(num[j] > num[j+1])
			{
				swap(num[j] , num[j+1]);
				bilozamjena = 1;
			}
			
		}
	}
	
	
}

void BubbleSort(int *num, int lenght)


{
    int i, j, flag = 1;    // set flag to 1 to start first pass
    int temp;             // holding variable
    int numLength = lenght;
    for (i = 1; (i <= numLength) && flag; i++)
    {
        flag = 0;
        for (j = 0; j < (numLength - 1); j++)
        {
            if (num[j + 1] > num[j])      // ascending order simply changes to <
            {
                temp = num[j];             // swap elements
                num[j] = num[j + 1];
                num[j + 1] = temp;
                flag = 1;               // indicates that a swap occurred.
            }
        }
    }
    return;   //arrays are passed to functions by address; nothing is returned
}


void SelectionSort(int *num, int lenght)
{
    int i, j, first, temp;
    int numLength = lenght;
    for (i = numLength - 1; i > 0; i--)
    {
        first = 0;                 // initialize to subscript of first element
        for (j = 1; j <= i; j++)   // locate smallest between positions 1 and i.
        {
            if (num[j] < num[first])
                first = j;
        }
        temp = num[first];   // Swap smallest found with element in position i.
        num[first] = num[i];
        num[i] = temp;
    }
    return;
}


void insertion_sort(int *arr, int length){
    int j, temp;

    for (int i = 0; i < length; i++){
        j = i;

        while (j > 0 && arr[j] < arr[j - 1]){
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

void zamjeni(int* lijevi, int* desni)
{
    int tmp = *lijevi;
    *lijevi = *desni;
    *desni = tmp;
}

int Partition(int *polje, int lijevo, int desno)
{
    int pivot = polje[lijevo];
//    printf("\nPivot:%d", pivot);
    int i = lijevo + 1;
    int j = desno;

    while (i <= j){
        while (polje[i] <= pivot && i <= desno)
        {
            i = i + 1;
        }
        while (polje[j] > pivot && j > lijevo)
        {
            j = j - 1;
        }
        if (i < j)
        {
            zamjeni(&polje[i], &polje[j]);
    //        printf("\nMjenjam %d , %d", polje[i], polje[j]);
        }
    }
    zamjeni(&polje[j], &polje[lijevo]);

//    printf("\nMjenjam pivota %d , %d", polje[j], polje[lijevo]);
//    printf("\n");
//    for (int i = 0; i <= desno; i++)
//    {
//        printf("%d ", polje[i]);
//    }
    return j;
}

void sort2(int* polje,int prvi, int drugi)
{
	if(polje[prvi] > polje[drugi])
	zamjeni(&polje[drugi], &polje[prvi]);
}

void sort3(int* polje,int prvi, int drugi, int treci)
{

if (polje[prvi] > polje[drugi])
   zamjeni(&polje[prvi],&polje[drugi]);
   
if (polje[drugi] > polje[treci])
   zamjeni(&polje[drugi],&polje[treci]);
   
if (polje[prvi] > polje[drugi])
   zamjeni(&polje[prvi],&polje[drugi]);
   
}


void QucikSortIter(int *polje, int lijevo, int desno)
{
    using namespace std;
    stack<int> stog;

    stog.push(desno);
    stog.push(lijevo);

    while (stog.empty() == false)
    {
        lijevo = stog.top();
        stog.pop();
        desno = stog.top();
        stog.pop();
        int j = Partition(polje, lijevo, desno);

        if (lijevo < (j - 1))
        {
            stog.push(j - 1);
            stog.push(lijevo);
        }

        if ((j + 1) < desno)
        {
            stog.push(desno);
            stog.push(j + 1);
        }

    }

}


void QuickSortRecOpt(int *polje, int lijevo, int desno)
{

    int j = Partition(polje, lijevo, desno);

        if (lijevo < (j - 1))
        {
        	//printf("%d ",(j-1) - lijevo);
        	if (((j-1) - lijevo) == 3)
			{
				sort3(polje,lijevo,lijevo+1,lijevo+2);
			}
			
        	else if(((j-1) - lijevo) == 2)
			{
				sort2(polje,lijevo,lijevo+1);
			}

			else if (((j-1) - lijevo) == 1)
			{
				if(polje[lijevo] > polje[lijevo+1])
				zamjeni(&polje[lijevo],&polje[lijevo+1]);
			}
			else
        	QuickSortRecOpt(polje,lijevo,j-1);
        }

        if ((j + 1) < desno)
        {
        	//printf("%d ",(j-1) - lijevo);
        	if ((desno - (j + 1)) == 3)
			{
				sort3(polje,desno-2,desno-1,desno);
			}
			
        	else if((desno - (j + 1)) == 2)
			{
				sort2(polje,desno-1,desno);
			}

			else if ((desno - (j + 1)) == 1)
			{
				if(polje[desno-1] > polje[desno])
				zamjeni(&polje[desno],&polje[desno-1]);
			}
			else
            QuickSortRecOpt(polje,j+1,desno);
    	}

}


void QuickSortRec(int *polje, int lijevo, int desno)
{

    int j = Partition(polje, lijevo, desno);

        if (lijevo < (j - 1))
        {
        	QuickSortRec(polje,lijevo,j-1);
        }

        if ((j + 1) < desno)
        {
           QuickSortRec(polje,j+1,desno);
    	}

}


int main()
{
   
    using namespace std;
    chrono::time_point<chrono::system_clock> pocetak, kraj;
    double t;
    int N;
    int Np = 1;
    int odabir = 0;
    int* polje = new int[10000000];
    int ispis = 0;

    srand((unsigned)time(NULL));

    chrono::duration<double> vrijeme;
    
    do{
    	printf("Zelite li ispis polja? 1 Da, 0 Ne\n");
    	scanf("%d",&ispis);
	}while(ispis != 1 && ispis != 0);
    

    do{
    	printf("Unesite sort: \n");
    	printf("1. insertion_sort\n");
    	printf("2. SelectionSort\n");
    	printf("3. BubbleSort\n");
    	printf("4. Partition\n");
    	printf("5. QucikSortIter\n");
    	printf("6. QuickSortRec\n");
    	printf("7. QuickSortRecOpt\n");
    	scanf("%d", &odabir);
    	
        printf("\nUnesite velicinu polja, max 10.000.000: ");
        scanf("%d", &N);
        printf("Unesite broj ponavljanja: ");
        scanf("%d", &Np);

        for (int i = 0; i < Np; i++)
        {
            //printf("\n");
            for (int i = 0; i < N; i++)
            {
                polje[i] = rand() % 1000;
                //    printf("%d ", polje[i]);
            }
            
            if(ispis)
            {
            	
            printf("\n");
           for (int i = 0; i < N; i++)
            {
                printf("%d ", polje[i]);
            }
			}


            pocetak = chrono::system_clock::now();
            switch(odabir)
            {
            	case 1: {
            		insertion_sort(polje,N);
					break;
				}
				case 2: {
            		SelectionSort(polje, N);
					break;
				}
				case 3: {
            		BubbleSort1(polje, N);
					break;
				}
				case 4: {
            		Partition(polje, 0, N - 1);
					break;
				}
				case 5: {
            		QucikSortIter(polje, 0, N - 1);
					break;
				}
				case 6: {
            		QuickSortRec(polje, 0, N - 1);
					break;
				}
				case 7: {
            		QuickSortRecOpt(polje, 0, N - 1);
					break;
				}
				default: {
					printf("Krivi unos!");
					break;
				}
			}

            kraj = chrono::system_clock::now();
            vrijeme += (kraj - pocetak);
            
            
            if(ispis)
            {
            	
          printf("\nSortirano: ");
          for (int i = 0; i < N; i++)
           {
              printf("%d ", polje[i]);
         }
			}


        }
        
        cout << (vrijeme.count() / Np) / (N*log10(N)) << endl; 
        cout << endl <<vrijeme.count() / Np <<endl;
        vrijeme = chrono::system_clock::duration::zero();

    } while (true);

    delete polje;

    return 0;
}
