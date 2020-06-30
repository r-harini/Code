#include<bits/stdc++.h> 
using namespace std; 
  
int firstFit(int blockSize[], int m, int processSize[], int n) 
{ 
    int allocation[n], allocated[n], extFrag=0; 
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) allocated[i] = -1;
    
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (blockSize[j] >= processSize[i] && allocated[j] != 0) { 
                allocation[i] = j; 
                allocated[j] = 0;
                extFrag += (blockSize[j] - processSize[i]);
                break; 
    } } } 

    cout << "\n* * * First Fit * * *\n";
    cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < n; i++) { 
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t"; 

        if (allocation[i] != -1) 
            cout << allocation[i] + 1; 
        else
            cout << "Not Allocated"; 
        
        cout << endl; 
        }
	cout << "Total External Fragmentation : " << extFrag;
return extFrag;
} 

int worstFit(int blockSize[], int m, int processSize[], int n) 
{ 
	int allocation[n], extFrag=0, allocated[n]; 
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) allocated[i] = -1;

	for (int i = 0; i < n; i++ ) { 
		int wstIdx = -1; 
		for (int j = 0; j < m; j++) { 
			if (blockSize[j] >= processSize[i] && allocated[j] != 0) { 
				if (wstIdx == -1) 
					wstIdx = j; 
				else if (blockSize[wstIdx] < blockSize[j]) 
					wstIdx = j; 
			} } 
		if (wstIdx != -1) { 
			allocation[i] = wstIdx; 
			allocated[wstIdx] = 0;
            extFrag += (blockSize[wstIdx] - processSize[i]);
		} 
	} 

    cout << "\n* * * Worst Fit * * *\n";
	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
	
	cout << "Total External Fragmentation : " << extFrag;
return extFrag;
} 

int bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
	int allocation[n], extFrag=0, allocated[n]; 
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) allocated[i] = -1;

	for (int i=0; i<n; i++) { 
		int bestIdx = -1; 
		for (int j=0; j<m; j++) { 
			if (blockSize[j] >= processSize[i] && allocated[j] != 0) { 
				if (bestIdx == -1) 
					bestIdx = j; 
				else if (blockSize[bestIdx] > blockSize[j]) 
					bestIdx = j; 
		} } 

		if (bestIdx != -1) { 
			allocation[i] = bestIdx; 
			allocated[bestIdx] = 0;
            extFrag += (blockSize[bestIdx] - processSize[i]);
		} } 

    cout << "\n* * * Best Fit * * *\n";
	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
	cout << "Total External Fragmentation : " << extFrag;
return extFrag;
} 

int main() 
{ 
    // int m, n, i;
    // cout << "\nEnter the total count of memory blocks : ";  cin >> m;
    // int blockSize[m];
    // for(i=0;i<m;i++)  {
    //     cout << "Enter memory block size : ";
    //     cin >> blockSize[i]; }


    // cout << "\nEnter the number of processes memory : ";
    // cin >> n;
    // int processSize[n];
    // for(i=0;i<n;i++) {
    //     cout << "Enter process memory size : ";
    //     cin >> processSize[i]; 
    // }

    int blockSize[] = {300, 600, 350, 200, 750, 125}; 
    int processSize[] = {115, 500, 358, 200, 375}; 
    int m = sizeof(blockSize) / sizeof(blockSize[0]); 
    int n = sizeof(processSize) / sizeof(processSize[0]); 
  
    cout << "\nBlock Seems to be as :\n";
    for(int i = 0; i < m; i++) cout << blockSize[i] << "-";
    cout << endl;
    
    int extFrag_first = firstFit(blockSize, m, processSize, n); 
    int extFrag_worst = worstFit(blockSize, m, processSize, n); 
	int extFrag_best = bestFit(blockSize, m, processSize, n); 

    if (extFrag_first < extFrag_worst && extFrag_first < extFrag_best) cout << "First Fit is the best algorithm.";
    else if (extFrag_worst < extFrag_best) cout << "Worst Fit is the best algorithm.";
    else  cout << "Best Fit is the best algorithm.";
    
    return 0 ; 
}