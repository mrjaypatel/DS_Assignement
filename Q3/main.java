// class named Main
public class Main {
    // main method
    public static void main(String[] args) {
        // declare an intger array as arr
        // and array must be sorted
        int arr[] = {1,3,4,5,6,7,8,9,12,14,16};
        // test for int x = 15
        int x = 15;
        System.out.println("\nIs there exist two elements whose sum is exactly " + x + ": ");
        IsSum(arr, x);
        // test for integer y = 31
        int y = 31;
        System.out.println("\nIs there exist two elements whose sum is exactly " + y + ": ");
        IsSum(arr, y);
    }
    // method named IsSum
    public static void IsSum(int arr[], int x) {
        int start = 0;
        int end = arr.length - 1;
        // using while loop with condition start < end
        while (start < end) {
            // if the sum of start and end element is equal to x then reak the loop
            if (arr[start] + arr[end] == x) {
                System.out.println(arr[start] + " and " + arr[end] + " are the elements that are equal to " + x);
                return;
            }
            // if x is greater then sum of start and end then update start by adding 1
            else if (arr[start] + arr[end] < x) {
                start++;
            }
            // if x is less then sum of start and end then update end by sub. 1
            else if (arr[start] + arr[end] > x) {
                end--;
            }
        }
        // in the end print No pair found whose sum is equal to x if not found
        System.out.println("No pair found whose sum is equal to " + x);
    }
}