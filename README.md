# CPlusPlus-Coursework
Final Project Code for MPCS 51044

This was the final project I used from C++.  The project was built in XCode but should have no problems with g++ or clang either.

If you are using XCode to compile and run the program, please note the following, and it is also documented in main.cpp.

    // Please note that if the 'C' function is not working, you need to
    // go to Product -> Scheme -> Edit Scheme -> Run (on left Menu)
    // -> Check box with "Use Custom Wroking Directory" -> Then add the Brabble directory
    // Uncomment the code below if you need to test the file connectivitiy
    
    /*
    std::ifstream myfile;
    myfile.open("brabblewords.txt");
    if (myfile.is_open()){
        std::cout << "File successfully open";
        myfile.close();
    } else {
        std::cout << "Error opening file";
    }
     */
