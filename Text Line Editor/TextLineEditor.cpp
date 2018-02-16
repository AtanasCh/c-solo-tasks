#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void printErrorMessage(int lineNumber){
    cout << endl << "  ERROR: The line " << lineNumber << " does not exist" << endl;
}

void writeVector(vector<string> vektor, ofstream &myfile1){


            for (int i = 0; i < vektor.size() + 1; i++){
                  cout << vektor[i] << endl;
                  myfile1 << vektor[i] << endl;
            }


}

 vector<string> fillVector(vector<string> vektor, string lines, ifstream &myfile1 ){

    while(getline(myfile1, lines)){
            vektor.push_back(lines);
    }

    return vektor;
}

main()
{


    vector<string> TextVector;

    cout << "Please enter the name of the file:" << endl;
    string filelocation;
    cin >> filelocation;


    ifstream myfile;
    myfile.open(filelocation.c_str());
    if (myfile.is_open()){
            cout << "File has opened successfully." << endl;

            } else {
            cout << "File hasn't opened successfully.";
            return 0;

        }
    myfile.close();

    while(true){

        cout << "Enter the text line number:" << endl;
        int line_number;
        cin >> line_number;

        string lines;
        myfile.open(filelocation.c_str());
        TextVector = fillVector(TextVector, lines, myfile);
        myfile.close();


        if(line_number > TextVector.size() + 1){

               printErrorMessage(line_number);

               return 0;
        }

        cout << TextVector[line_number] << endl;
        cout << "If you'd like to change the line, please enter the line, otherwise enter n to exit" << endl;
                    string changeLine;
                    std::cin.ignore(INT_MAX,'\n');
                    getline(cin, changeLine);


        if (changeLine == "n"){
            myfile.close();
            return 0;
        }

        TextVector[line_number] = changeLine;

        cout << "Would you like to enter a new line to edit? (Y/n)" << endl;
        string newLine;
        cin >> newLine;
        if (newLine != "y" && newLine != "Y"){


                    cout << "Would you like to save all your changes to the file? (Y/n)" << endl;
                    string saveChanges;
                    cin >> saveChanges;

                    if (saveChanges != "y" && saveChanges != "Y"){
                             myfile.close();
                             return 0;
                    }

                            ofstream myfile1;
                            myfile1.open(filelocation.c_str());
                            writeVector(TextVector, myfile1);
                            myfile1.close();

            return 0;
        }



        }
    return 0;
}
