//#include <iostream>
//#include <cmath>
//using namespace std;
//
//void creation_of_set(int set[], int& size)
//{
//    for (int i = 0; i < size; i++) 
//    {
//        cout << "Enter value of element " << i + 1 << ": ";
//        cin >> set[i];
//    }
//    cout << endl;
//}
//
//void print_set(const int set[], int size) 
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << set[i] << " ";
//    }
//    cout << endl;
//}
//
//int set_of_union(const int a[], int sizeA, const int b[], int sizeB, int result[])
//{
//    int index = 0;
//    for (int i = 0; i < sizeA; i++) 
//    {
//        result[index++] = a[i];
//    }
//
//    for (int i = 0; i < sizeB; i++)
//    {
//        bool found = false;
//        for (int j = 0; j < sizeA; j++) 
//        {
//            if (b[i] == a[j]) 
//            {
//                found = true;
//                break;
//            }
//        }
//        if (!found) 
//        {
//            result[index++] = b[i];
//        }
//    }
//    return index;
//}
//
//int set_of_intersection(const int a[], int sizeA, const int b[], int sizeB, int result[])
//{
//    int index = 0;
//    for (int i = 0; i < sizeA; i++) 
//    {
//        for (int j = 0; j < sizeB; j++) 
//        {
//            if (a[i] == b[j]) 
//            {
//                result[index++] = a[i];
//                break;
//            }
//        }
//    }
//    return index;
//}
//
//int set_of_difference(const int a[], int sizeA, const int b[], int sizeB, int result[])
//{
//    int index = 0;
//    for (int i = 0; i < sizeA; i++) 
//    {
//        bool found = false;
//        for (int j = 0; j < sizeB; j++)
//        {
//            if (a[i] == b[j])
//            {
//                found = true;
//                break;
//            }
//        }
//        if (!found)
//        {
//            result[index++] = a[i];
//        }
//    }
//    return index;
//}
//
//int total_relation(int sizeA, int sizeB) 
//{
//    return pow(2, sizeA * sizeB);
//}
//
//void input_relation(int relations[][2], int& num_of_Relation) 
//{
//    cout << "Enter the number of pairs in relations: ";
//    cin >> num_of_Relation;
//    cout << "Enter relations as pairs (e.g., 1 2):" << endl;
//    for (int i = 0; i < num_of_Relation; i++) 
//    {
//        cin >> relations[i][0] >> relations[i][1];
//    }
//}
//
//bool check_reflexive(const int relations[][2], int num_of_Relation, const int set[], int size) 
//{
//    for (int i = 0; i < size; i++) 
//    {
//        bool found = false;
//        for (int j = 0; j < num_of_Relation; j++)
//        {
//            if (relations[j][0] == set[i] && relations[j][1] == set[i]) 
//            {
//                found = true;
//                break;
//            }
//        }
//        if (!found) return false;
//    }
//    return true;
//}
//
//bool check_symmetric(const int relations[][2], int num_of_Relation) 
//{
//    for (int i = 0; i < num_of_Relation; i++) 
//    {
//        bool found = false;
//        for (int j = 0; j < num_of_Relation; j++)
//        {
//            if (relations[i][0] == relations[j][1] && relations[i][1] == relations[j][0]) 
//            {
//                found = true;
//                break;
//            }
//        }
//        if (!found) return false;
//    }
//    return true;
//}
//
//bool check_antisymmetric(const int relations[][2], int num_of_Relation) 
//{
//    for (int i = 0; i < num_of_Relation; i++)
//    {
//        if (relations[i][0] != relations[i][1]) 
//        {
//            for (int j = 0; j < num_of_Relation; j++) 
//            {
//                if (relations[i][0] == relations[j][1] && relations[i][1] == relations[j][0])
//                {
//                    return false;
//                }
//            }
//        }
//    }
//    return true;
//}
//
//static void print()
//{
//    cout << "\n\n\t\t\t\t\t\t--> Please choose an operation <--" << endl;
//    cout << "\t\t\t1) Create the sets\n";
//    cout << "\t\t\t2) Print sets\n";
//    cout << "\t\t\t3) Union of A and B\n";
//    cout << "\t\t\t4) Intersection of A and B\n";
//    cout << "\t\t\t5) A - B\n";
//    cout << "\t\t\t6) B - A\n";
//    cout << "\t\t\t7) Total number of relations\n";
//    cout << "\t\t\t8) Reflexive Relations\n";
//    cout << "\t\t\t9) Symmetric Relations\n";
//    cout << "\t\t\t10) Anti - Symmetric Relations\n";
//    cout << "\t\t\t11) Exit\n";
//}
//
//int main() 
//{
//    int setA[100], setB[100], unionResult[200], intersectionResult[100], differenceResult[100];
//    int sizeA = 0, sizeB = 0, choice, noOfRelations, relations[100][2];
//
//    while (true) 
//    {
//        print();
//        cout << "Enter Your Choice: ";
//        cin >> choice; cout << endl;
//
//        if (choice == 1) 
//        {
//            cout << "Number of elements in Set A: ";
//            cin >> sizeA;
//            creation_of_set(setA, sizeA);
//
//            cout << "Number of elements in Set B: ";
//            cin >> sizeB;
//            creation_of_set(setB, sizeB);
//        }
//        else if (choice == 2) 
//        {
//            cout << "Set A: ";
//            print_set(setA, sizeA);
//            cout << "Set B: ";
//            print_set(setB, sizeB);
//        }
//        else if (choice == 3)
//        {
//            int unionSize = set_of_union(setA, sizeA, setB, sizeB, unionResult);
//            cout << "Union of A and B: ";
//            print_set(unionResult, unionSize);
//        }
//        else if (choice == 4) 
//        {
//            int intersectionSize = set_of_intersection(setA, sizeA, setB, sizeB, intersectionResult);
//            cout << "Intersection of A and B: ";
//            print_set(intersectionResult, intersectionSize);
//        }
//        else if (choice == 5) 
//        {
//            int differenceSize = set_of_difference(setA, sizeA, setB, sizeB, differenceResult);
//            cout << "Difference A - B: ";
//            print_set(differenceResult, differenceSize);
//        }
//        else if (choice == 6) 
//        {
//            int differenceSize = set_of_difference(setB, sizeB, setA, sizeA, differenceResult);
//            cout << "Difference B - A: ";
//            print_set(differenceResult, differenceSize);
//        }
//        else if (choice == 7) 
//        {
//            cout << "Total number of relations: " << total_relation(sizeA, sizeB) << endl;
//        }
//        else if (choice == 8) 
//        {
//            input_relation(relations, noOfRelations);
//            if (check_reflexive(relations, noOfRelations, setA, sizeA)) 
//            {
//                cout << "The relation is reflexive." << endl;
//            }
//            else
//            {
//                cout << "The relation is not reflexive." << endl;
//            }
//        }
//        else if (choice == 9)
//        {
//            input_relation(relations, noOfRelations);
//            if (check_symmetric(relations, noOfRelations)) 
//            {
//                cout << "The relation is symmetric." << endl;
//            }
//            else
//            {
//                cout << "The relation is not symmetric." << endl;
//            }
//        }
//        else if (choice == 10)
//        {
//            input_relation(relations, noOfRelations);
//            if (check_antisymmetric(relations, noOfRelations)) 
//            {
//                cout << "The relation is antisymmetric." << endl;
//            }
//            else 
//            {
//                cout << "The relation is not antisymmetric." << endl;
//            }
//        }
//        else if (choice == 11) 
//        {
//            cout << "Exiting program." << endl;
//            break;
//        }
//        else 
//        {
//            cout << "Invalid choice! Please try again." << endl;
//        }
//    }
//    cout << endl << endl;
//    system("pause");
//    return 0;
//}
