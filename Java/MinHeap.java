import java.util.*;
import java.io.*;

public class MinHeap {
    /**
	 *	<pre>
	 *	CSCI3220 2018-19 First Term Assignment 5
	 *	This is a class for for data structure heap.
	 *	</pre>
	 *
	 *	@author		Nigel Nicholas
	 *	@version	1.0 (10th December 2018)
	 *
	 *	<pre>
	 *	Change History:
	 *	1.0	- Initial version
	 *	</pre>
	 */
    
    //-------------------------------------------
    // Class Variable
    //-------------------------------------------
    protected int size;
    protected List<Integer> heap = new ArrayList<Integer>(); //   Heap is Basically an integer array(list)
    /**
     * Class Constructor of MinHeap
     * @param none
     */
    public MinHeap() {
        
        Scanner reader = new Scanner(System.in); //     reader for the prompt from question
        this.size  = reader.nextInt();    //         holds the number of input
        for(int i = 0 ; i<this.size; i++) {
            int x = reader.nextInt();
            this.heap.add(x);    //          loops and add integer to the list dynamically
        }


    }   //      end of constructor MinHeap
    
    
    /**
     * function to swap number on index1 and index2 of the heap(list)
     * @param index1 : first index for swapping
     * @param index2 : second index for swapping
     */
    void swap(int index1, int index2){
        List<Integer> heap = this.heap;
        Collections.swap(heap, index1, index2);
    }   //          end of function swap


    /**
     * to turn the main list into the heap property structure
     * @param heap: list
     */
    void heapify() {
        int size = this.size;

        // loop from index (size-1)/2 down to 0 and check all
        for(int i=(size-1)/2; i>=0; i--) {
            this.bubbleUp(i);
        }

    }   //          end of function heapify

    /**
     * return whether true/false that that particular index contains child
     * @param index
     * @return boolean
     */
    boolean hasChild(int index){
        int size = this.size;
        if(size>(2*index)+1) return true;
        return false;
    }   //              end of function hasChild

    /**
     * bubble up takes a trio(or duo) and make the parent node
     * be the minimum of the trio/duo relation
     * @param index
     */
    void bubbleUp(int index){
        if(!this.hasChild(index)) return;
        
        int size = this.size;
        int leftindex = (2*index) + 1; 
        int rightindex = (2*index) + 2;
        int parent = this.heap.get(index);
        
        int left = this.heap.get(leftindex);
        int right = 1000000; //         just as initializer and give it big number so that anything else will always be smaller
        if(this.containsRightChild(index)){
            right = this.heap.get((rightindex)); //        just to check to avoid the index out of bound error
        }

        if(this.containsRightChild(index)){ //      if it has right child we need to compare all the left right and parent
            if(left<parent && left<right) {this.swap(leftindex,index);this.bubbleUp(leftindex);}
            if(right<parent && right<left) {this.swap(rightindex,index);this.bubbleUp(rightindex);}


        }
        else {  //      if no right child then simply compare the 
            if(left<parent){this.swap(leftindex,index);this.bubbleUp(leftindex);}
        }   


    }   // end of function bubbleUp

    /**
     * check whether a node has right child( 2*i + 2 )
     * @param index
     * @return
     */
    boolean containsRightChild(int index) {
        int size = this.size;
        if((2*index)+2 <size) return true;
        else return false;
    
    }  //           end of function containsRightChild

    /**
     * function to delete minimum and adjust immediately 
     * to save heap property
     */
    void deleteMin() {
        List<Integer> heap = this.heap;
        int size = this.size;

        // since if you remove, the list adjust itself
        // then swap first with last and remove the last element
        
        this.swap(0, size - 1);
        heap.remove(size - 1);   // after removing the last one 
        this.size -= 1; 

        // then heapify again
        this.heapify();
        
    }

    /**
     * function to iterate the list in order to
     * follow format
     */
    void iteratelist() {
        List<Integer> heap = this.heap;
        Iterator<Integer> iter = heap.iterator();
        String cache = new String();

        for(int i=0; i<heap.size(); i++ ) {
            cache += heap.get(i).toString();
            if(i != heap.size() -1 ) cache+=',';    
        }
        System.out.println(cache);
    }


     /**
      * Main function 
      * @param args
      */
 public static void main(String[] args) {
        MinHeap start = new MinHeap();
        start.heapify();    //      after heapify, the list now contains the heap property
        int size = start.size;

        for(int i=0; i<size; i++) {
            start.iteratelist();
            start.deleteMin();

        }


    }


}