 class Main {
        public static boolean  findDuplicateinK(int n, int[] array, int k) {

                for (int i = 0; i < n - k + 1; i++) {
                        for (int j = i+1; j < i + k; j++) {
                                if (array[i] == array[j]) {
                                        return true;
                                }
                        }
                }
                return false;
        }

        public static void main(String[] args) {
          int[] array = {1,2,3,4,3,3};
          System.out.println(findDuplicateinK(6,array,2));
          System.out.println(findDuplicateinK(6,array,5));
        }

}
