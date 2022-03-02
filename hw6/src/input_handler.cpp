#include "input_handler.h"
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

void InputHandler::handle() {
    
        printEditorInstructions();    
        int instruction=0;
        cin>>instruction;
        handleEditorInstructions(instruction);
    
}

void InputHandler::printEditorInstructions() {
     cout<<"Please enter the following instruction number to start building:\n"
                "  1. 'add circle': to add a circle\n"
                "  2. 'add rectangle': to add a rectangle\n"
                "  3. 'add triangle': to add a triangle\n"
                "  4. 'add compound': to add a compound\n"
                "  5. 'save': output shape to file\n"
                "  6. 'exit': to exit the program\n";
}

void InputHandler::handleEditorInstructions(int instruction) {
      int compoundInstruction=0;  
      
      switch (instruction)
        {
        case 1:
            addCircle();
            handle(); 
            break;
        case 2:
            addRectangle();
            handle(); 
            break;
        case 3:
            addTriangle();
            handle(); 
            break;
        case 4:
            isContinued=false;
            addCompound();
            printCompoundInstructions();
            handle(); 
            break;
        case 5:
            save();
            handle(); 
            break;
        case 6:
            break;
        default:
            cout<<"Invalid instruction. Please try again.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            handle(); 
            break;
        }
}

void InputHandler::save() {
    cout<<"Please enter the file name to save the shape:\n";
    string output="";
    cin>>output;
    ShapeInfoVisitor s;
    builder->getShape()->accept(&s);

    ofstream ofs;
    ofs.open(output);
    ofs <<s.getResult();
    ofs.close();
    cout<<"Save complete.";
    compoundNumber=0;
    builder->reset();
}

void InputHandler::addCircle() {
    cout<<"Please enter the information of circle:\n";
    cout<<"Radius of circle: ";
    float Radius=0;
    cin>>Radius;
    
    if(Radius>0){
        builder->buildCircle(Radius);
        Circle c(Radius);
        cout<<"Circle added.\n";

    }else{
        cout<<"Invalid argument. Please try again.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void InputHandler::addRectangle() {
    cout<<"Please enter the information of rectangle:\n";
    cout<<"Width of rectangle: ";
    float width=0;
    cin>>width;
    cout<<"Height of rectangle: ";
    float height=0;
    cin>>height;
    if(width>0 && height>0 ){
        builder->buildRectangle(width,height);
        cout<<"Rectangle added.\n";
    }else{
        cout<<"Invalid argument. Please try again.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void InputHandler::addTriangle() {
    cout<<"Please enter the information of triangle:\n";
    cout<<"X1 of triangle: ";
    float x1=0;
    cin>>x1;
    cout<<"Y1 of triangle: ";
    float y1=0;
    cin>>y1;
    cout<<"X2 of triangle: ";
    float x2=0;
    cin>>x2;
    cout<<"Y2 of triangle: ";
    float y2=0;
    cin>>y2;
    TwoDimensionalVector t1(x1,y1);
    TwoDimensionalVector t2(x2,y2);
    try{
        Triangle(t1,t2);
        builder->buildTriangle(x1,y1,x2,y2);
        cout<<"Triangle added.\n";
    }catch(string e){
        cout<<"Invalid argument. Please try again.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void InputHandler::printCompoundInstructions() {
    
    int compoundInstruction=0;  
    cout<<"Please enter the following instruction number to build the compound "<< compoundNumber+1 <<":\n"
        "  1. 'add circle': to add a circle\n"
        "  2. 'add rectangle': to add a rectangle\n"
        "  3. 'add triangle': to add a triangle\n"
        "  4. 'add compound': to add a compound\n"
        "  5. 'exit': to exit the program\n";
    cin>>compoundInstruction;
    handleCompoundInstructions(compoundInstruction); 
}

void InputHandler::handleCompoundInstructions(int instruction) {

     switch (instruction)
        {
        case 1:
            addCircle();
            printCompoundInstructions();
            break;
        case 2:
            addRectangle();
            printCompoundInstructions();
            break;
        case 3:
            addTriangle();
            printCompoundInstructions();
            break;
        case 4:
            addCompound();
            isContinued = true;
            compoundNumber++;
            printCompoundInstructions();
            break;
        case 5:
            builder->buildCompoundEnd();
            compoundNumber--;
            if(compoundNumber<0) isContinued = false;
            if(isContinued){
                cout<<"Compound "<<compoundNumber+2<<" added. \n";
                printCompoundInstructions();             
            }else{
                cout<<"Compound "<<compoundNumber+2<<" added. \n";
                cout << "Finish to add a compound shape.\n";
            }
            break;
        default:
            cout<<"Invalid instruction. Please try again.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printCompoundInstructions();
            break;
        }

    
}

void InputHandler::addCompound() {
    builder->buildCompoundBegin();
}