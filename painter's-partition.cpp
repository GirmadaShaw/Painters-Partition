/*
Given are N boards of with length of each given in the form of array, and K painters, 
such that each painter takes 1 unit of time to paint 1 unit of the board. The task is to 
find the minimum time to paint all boards under the constraints that any painter will 
only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but 
not board {2, 4, 5}.

Input: N = 4, A = {10, 10, 10, 10}, K = 2 
Output : 20
Explanation: Here we can divide the +boards into 2 equal sized partitions 
            (Painter 1 will paint boards A1 and A2, and Painter 2 will paint boards A3 and A4). 
            So each painter gets 20 units of board and the total time taken is 20. 

Input: N = 4, A = {10, 20, 30, 40}, K = 2 
Output : 60
Explanation: Since there are only 2 painters, therefore divide first 3 boards to painter 1
             (A1, A2 and A3) with time = 60, and last board to painter 2 (A4) with time = 40. 
             Therefore total time taken = 60, which is the minimum possible.

Please note the combination A1 and A4 to Painter 1 with time 50, and A2 and A3 to Painter 2 
with time 50, will yield a smaller time (50 units). But this cant be considered due to the 
constraint that a painter cannot paint non-continuos series of boards.
*/

//Time Complexity: O(nlogn)   Space-Complexity: O(1)
#include <iostream>

bool isPossible( int arr[] , int size , int k , int mid )
{
    int PainterCount = 1 , lengthPainted = 0 ;

    for ( int i = 0 ; i < size ; i ++ )
    {
        if( lengthPainted + arr[i] <= mid )
            lengthPainted += arr[i] ;
        else 
        {
            PainterCount ++ ;
            if ( PainterCount > k || arr[i] > mid )
                return false ;

            lengthPainted = arr[i] ;
        }
    }
    return true ; 
}

int main()
{ 
    int arr[] = {10, 20, 30, 40} ;
    int size = sizeof( arr ) / sizeof( arr[0] ) ;
    int k = 2 ; 

    int sum = 0 ; 
    for ( int i = 0 ; i < size ; i++ )
        sum += arr[i] ;

    int start = arr[ size - 1 ] , end = sum , mid = start + ((end-start)/2) , ans = -1 ; 

    while ( start <= end ) 
    {
        if ( isPossible( arr , size , k , mid ) )
        {
            ans = mid ; 
            end = mid - 1 ;
        }
        else 
        {
            start = mid + 1 ;
        }
        mid = start + ((end-start)/2) ;
    }

    std :: cout  << "Required time is: " << ans << "s " ; 
}