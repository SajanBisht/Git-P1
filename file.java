import java.util.*;

public class file {
   int binary(int arr[], int lb, int up, int target) {
    // Base case: when lb > up, stop recursion
    if (lb > up) {
        return 0;
    }
    
    int mid = (lb + up) / 2;
    int count = 0;
    
    // If the target is found at mid, count it
    if (arr[mid] == target) {
        count = 1;
    }

    // Recursive call to check for target in the left half
    count += binary(arr, lb, mid - 1, target);
    
    // Recursive call to check for target in the right half
    count += binary(arr, mid + 1, up, target);
    
    return count;
}


    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n, target;
        
        System.out.println("Enter size of array:");
        n = Integer.parseInt(sc.next());
        
        int arr[] = new int[n];
        System.out.println("Enter elements of array:");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(sc.next());
        }
        
        System.out.println("Enter target:");
        target = Integer.parseInt(sc.next());
        
        // Sort the array 
        Arrays.sort(arr);
        
        file obj = new file();
        int count = obj.binary(arr, 0, n - 1, target);
        
        if (count == 0) {
            System.out.println("Not present");
        } else {
            System.out.println("Present: " + count);
        }
        
        sc.close();
    }
}

