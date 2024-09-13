#include <iostream>
#include <cstdlib>
#include <ctime>


int main(){
	
	const int areaSize = 11;
	
	const int elementSize = (areaSize - 2) / 3;
	int elementsCount = 9;
	const int ARR_SIZE = 3;
	char elementsArr[ARR_SIZE][ARR_SIZE];
	
	for (int i = 0;i<ARR_SIZE;i++){
		for (int j=0;j<ARR_SIZE;j++){
			elementsArr[i][j] = ' ';
		}
	}
	
	int randCoordX,randCoordY;
	
	std::srand(time(0));
	
	
	char userElement;
	char botElement;
	std::cout<<"Which element do you want X|O: ";
	std::cin>>userElement;
	
	if (userElement == 'x'){
		userElement-=32;
		botElement = 'O';
	}
	else if (userElement == 'o'){
		userElement-=32;
		botElement = 'X';
	}
	
	char gameArea[areaSize][areaSize];
	for (int k=0;k<areaSize;k++){
		for (int l=0;l<areaSize;l++){
			if (k == areaSize / 3 || k == (areaSize / 3) * 2 + 1){
				gameArea[k][l] = '#';
				}
			else if(l == areaSize / 3 || l == (areaSize / 3) * 2 + 1){
				gameArea[k][l] = '#';
			}
			else{
				gameArea[k][l] = ' ';
			}
		}
	}
	
	bool exitLoop;
	int coordX,coordY;
	bool checkWinner = true;
	char winner;
	if (userElement == 'X'){
		while(elementsCount>=0 && checkWinner){
			exitLoop = false;
			while(true){
				while (true){
					std::cout<<"Enter coordinate X (1-3): ";
					std::cin>>coordX;
					
					if (coordX > 3 || coordX < 1){
						std::cout<<"Wrong input! Enter coordinate X between 1-3.\n";
						continue;
					}
					else{
						break;
					}
				}
				while (true){
					std::cout<<"Enter coordinate Y (1-3): ";
					std::cin>>coordY;
					
					if (coordY > 3 || coordY < 1){
						std::cout<<"Wrong input! Enter coordinate Y between 1-3.\n";
						continue;
					}
					else{
						break;
					}
				}
				if(elementsArr[coordX - 1][coordY - 1] == 'X' || elementsArr[coordX - 1][coordY - 1] == 'O'){
					std::cout<<"Please enter your element to empty place.\n";
					continue;
				}
				else{
					elementsArr[coordX - 1][coordY - 1] = 'X';
					exitLoop = true;
					break;
				}
				if (exitLoop){
					break;
				}
			}
			elementsCount--;
			
			for (int i = 0; i < ARR_SIZE; i++) {
    			for (int j = 0; j < ARR_SIZE; j++) {
        			if (elementsArr[i][j] == 'X') {
            			int tempI = i * 4;
            			int tempJ = j * 4;

            			for (int m = 0; m < elementSize; m++) {
                			for (int n = 0; n < elementSize; n++) {
                    			if (m == n || m + n == 2) {
                        			gameArea[tempI + m][tempJ + n] = 'X';
                    			}
                			}
            			}
        			}
        			else if (elementsArr[i][j] == 'O'){
        				int tempI = i * 4;
        				int tempJ = j * 4;
        	
        				for (int m = 0; m < elementSize; m++){
        					for (int n = 0; n < elementSize; n++){
        						if (m != n && m + n != 2){
        						gameArea[tempI + m][tempJ + n] = 'O';
								}
							}
						}
					}
    			}
			}
			
			
			if (elementsArr[0][0] == 'X' && elementsArr[0][1] == 'X' && elementsArr[0][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[1][0] == 'X' && elementsArr[1][1] == 'X' && elementsArr[1][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[2][0] == 'X' && elementsArr[2][1] == 'X' && elementsArr[2][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][0] == 'X' && elementsArr[1][1] == 'X' && elementsArr[2][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][2] == 'X' && elementsArr[1][1] == 'X' && elementsArr[2][0] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][0] == 'X' && elementsArr[1][0] == 'X' && elementsArr[2][0] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][1] == 'X' && elementsArr[1][1] == 'X' && elementsArr[2][1] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][2] == 'X' && elementsArr[1][2] == 'X' && elementsArr[2][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			
			
			while (elementsCount > 0 && checkWinner){
				if (std::rand()%2==0){
					randCoordX = std::rand() % 3;
					randCoordY = randCoordX;
				}
				else{
					while (true){
						randCoordX = std::rand() % 3;
						randCoordY = std::rand() % 3;
						
						if (randCoordX != randCoordY){
							break;
						}
					}
				}
				
				if (elementsArr[randCoordX][randCoordY] == 'X' || elementsArr[randCoordX][randCoordY] == 'O'){
					continue;
				}
				else{
					elementsArr[randCoordX][randCoordY] = 'O';
					exitLoop = true;
					break;
				}
				if (exitLoop){
					break;
				}
			}
			
			
			
			elementsCount--;
			for (int i = 0; i < ARR_SIZE; i++) {
    			for (int j = 0; j < ARR_SIZE; j++) {
        			if (elementsArr[i][j] == 'X') {
            			int tempI = i * 4;
            			int tempJ = j * 4;

            			for (int m = 0; m < elementSize; m++) {
                			for (int n = 0; n < elementSize; n++) {
                    			if (m == n || m + n == 2) {
                        			gameArea[tempI + m][tempJ + n] = 'X';
                    			}
                			}
            			}
        			}
        			else if (elementsArr[i][j] == 'O'){
        				int tempI = i * 4;
        				int tempJ = j * 4;
        	
        				for (int m = 0; m < elementSize; m++){
        					for (int n = 0; n < elementSize; n++){
        						if (m != n && m + n != 2){
        						gameArea[tempI + m][tempJ + n] = 'O';
								}
							}
						}
					}
    			}
			}
			
			
			if (elementsArr[0][0] == 'O' && elementsArr[0][1] == 'O' && elementsArr[0][2] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
			}
			else if(elementsArr[1][0] == 'O' && elementsArr[1][1] == 'O' && elementsArr[1][2] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
			}
			else if(elementsArr[2][0] == 'O' && elementsArr[2][1] == 'O' && elementsArr[2][2] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
			}
			else if(elementsArr[0][0] == 'O' && elementsArr[1][1] == 'O' && elementsArr[2][2] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
			}
			else if(elementsArr[0][2] == 'O' && elementsArr[1][1] == 'O' && elementsArr[2][0] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
			}
			else if(elementsArr[0][0] == 'O' && elementsArr[1][0] == 'O' && elementsArr[2][0] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
			}
			else if(elementsArr[0][1] == 'O' && elementsArr[1][1] == 'O' && elementsArr[2][1] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
			}
			else if(elementsArr[0][2] == 'O' && elementsArr[1][2] == 'O' && elementsArr[2][2] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
			}
			

        	
        	for (int i = 0; i < areaSize; i++) {
            	for (int j = 0; j < areaSize; j++) {
                	std::cout << gameArea[i][j] << " ";
            	}
            	std::cout << std::endl;
        	}
		}
	}
	
	else if (botElement == 'X') {
    	while (elementsCount > 0 && checkWinner) {
        	exitLoop = true;
        	
        	while (exitLoop && elementsCount > 0) {
            	
            	if (std::rand() % 2 == 0) {
                	randCoordX = std::rand() % 3;
                	randCoordY = randCoordX;
            	} 
				else {
                	while (true) {
                    	randCoordX = std::rand() % 3;
                    	randCoordY = std::rand() % 3;

                    	if (randCoordX != randCoordY) {
                        	break;
                    	}
                	}
            	}

            	if (elementsArr[randCoordX][randCoordY] == 'X' || elementsArr[randCoordX][randCoordY] == 'O') {
                	continue;
            	} 
				else {
                	elementsArr[randCoordX][randCoordY] = 'X';
                	exitLoop = false;
                	elementsCount--;
            	}
        	}

        	for (int i = 0; i < ARR_SIZE; i++) {
    			for (int j = 0; j < ARR_SIZE; j++) {
        			if (elementsArr[i][j] == 'X') {
            			int tempI = i * 4;
            			int tempJ = j * 4;

            			for (int m = 0; m < elementSize; m++) {
                			for (int n = 0; n < elementSize; n++) {
                    			if (m == n || m + n == 2) {
                        			gameArea[tempI + m][tempJ + n] = 'X';
                    			}
                			}
            			}
        			}
        			else if (elementsArr[i][j] == 'O'){
        				int tempI = i * 4;
        				int tempJ = j * 4;
        	
        				for (int m = 0; m < elementSize; m++){
        					for (int n = 0; n < elementSize; n++){
        						if (m != n && m + n != 2){
        						gameArea[tempI + m][tempJ + n] = 'O';
								}
							}
						}
					}
    			}
			}
			
			
        	
        	for (int i = 0; i < areaSize; i++) {
            	for (int j = 0; j < areaSize; j++) {
                	std::cout << gameArea[i][j] << " ";
            	}
            	std::cout << std::endl;
        	}
        	
        if (elementsArr[0][0] == 'O' && elementsArr[0][1] == 'O' && elementsArr[0][2] == 'O'){
				checkWinner = false;
				winner = 'O';
				break;
		}
		else if(elementsArr[1][0] == 'O' && elementsArr[1][1] == 'O' && elementsArr[1][2] == 'O'){
			checkWinner = false;
			winner = 'O';
			break;
		}
		else if(elementsArr[2][0] == 'O' && elementsArr[2][1] == 'O' && elementsArr[2][2] == 'O'){
			checkWinner = false;
			winner = 'O';
			break;
		}
		else if(elementsArr[0][0] == 'O' && elementsArr[1][1] == 'O' && elementsArr[2][2] == 'O'){
			checkWinner = false;
			winner = 'O';
			break;
		}
		else if(elementsArr[0][2] == 'O' && elementsArr[1][1] == 'O' && elementsArr[2][0] == 'O'){
			checkWinner = false;
			winner = 'O';
			break;
		}
		else if(elementsArr[0][0] == 'O' && elementsArr[1][0] == 'O' && elementsArr[2][0] == 'O'){
			checkWinner = false;
			winner = 'O';
			break;
		}
		else if(elementsArr[0][1] == 'O' && elementsArr[1][1] == 'O' && elementsArr[2][1] == 'O'){
			checkWinner = false;
			winner = 'O';
			break;
		}
		else if(elementsArr[0][2] == 'O' && elementsArr[1][2] == 'O' && elementsArr[2][2] == 'O'){
			checkWinner = false;
			winner = 'O';
			break;
		}	

        
        	exitLoop = true;
        	while (exitLoop && elementsCount > 0 && checkWinner) {
            	while (true) {
                	std::cout << "Enter coordinate X (1-3): ";
                	std::cin >> coordX;
                	if (coordX > 3 || coordX < 1) {
                    	std::cout << "Wrong input! Enter coordinate X between 1-3.\n";
                    	continue;
                	} 
					else {
                    	break;
                	}
            	}
            	
            	while (true) {
                	std::cout << "Enter coordinate Y (1-3): ";
                	std::cin >> coordY;
                	if (coordY > 3 || coordY < 1) {
                    	std::cout << "Wrong input! Enter coordinate Y between 1-3.\n";
                    	continue;
                	} 
					else {
                    	break;
                	}
            	}
            	if (elementsArr[coordX - 1][coordY - 1] == 'X' || elementsArr[coordX - 1][coordY - 1] == 'O') {
                	std::cout << "Please enter your element to empty place.\n";
                	continue;
            	} 
				else {
                	elementsArr[coordX - 1][coordY - 1] = 'O';
                	exitLoop = false;
                	elementsCount--;
            	}
        	}
        	if (elementsArr[0][0] == 'X' && elementsArr[0][1] == 'X' && elementsArr[0][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[1][0] == 'X' && elementsArr[1][1] == 'X' && elementsArr[1][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[2][0] == 'X' && elementsArr[2][1] == 'X' && elementsArr[2][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][0] == 'X' && elementsArr[1][1] == 'X' && elementsArr[2][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][2] == 'X' && elementsArr[1][1] == 'X' && elementsArr[2][0] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][0] == 'X' && elementsArr[1][0] == 'X' && elementsArr[2][0] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][1] == 'X' && elementsArr[1][1] == 'X' && elementsArr[2][1] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
			else if(elementsArr[0][2] == 'X' && elementsArr[1][2] == 'X' && elementsArr[2][2] == 'X'){
				checkWinner = false;
				winner = 'X';
				break;
			}
    	}
	}		
	
	std::cout<<"\n\n\n\n\n\n\n";
	
	
	for (int i = 0; i < areaSize; i++) {
    	for (int j = 0; j < areaSize; j++) {
            std::cout << gameArea[i][j] << " ";
        }
        std::cout << std::endl;
    }
	
	if (winner == 'X' || winner == 'O'){
		std::cout<<"********************\n";
		std::cout<<"THE WINNER: "<<winner<<std::endl;
		std::cout<<"********************\n";
	}
	else{
		std::cout<<"********************\n";
		std::cout<<"NO WINNER ---> DRAW!"<<std::endl;
		std::cout<<"********************\n";
	}
	
	
	
	return 0;
}