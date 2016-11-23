
public class main{

	public static void main(String[] args) {

		/*	
		 *	coding time: under 30 min
		 *	runtime: O(m + n)
		 */

		// get the data for each of the books
		String book1 = "";
		
		String book2 = "";

		// initialize book pointers
		int book1_ptr = 0;
		int book2_ptr = 0;

		// O(1) lookup
		int[] dictionary = new int[256];
		for(int i = 0 ; i < 256 ; i++) {
			dictionary[i] = 0;
		}
		
		// we have exhausted book1 resources
		boolean finished = false;
		boolean success = false;

		// main program loop
		while(!finished) {

			// if we have reached the end of the second book
			if(book2_ptr >= book2.length()) {
				success = true;
				break;
			}

			// get the current char in book2
			char curr = book2.charAt(book2_ptr);

			// is there already a character available
			while(dictionary[(int) curr] == 0 ) {

				// failure
				if(book1_ptr >= book1.length()) {
					finished = true;
					break;

				// we can continue searching book1	
				} else {
					dictionary[(int) book1.charAt(book1_ptr)]++;
					book1_ptr++;
				}
			}

			// readjust the dict + pointer
			dictionary[(int) curr]--;
			book2_ptr++;			

		}

		// print results
		if(success) {
			System.out.println("success");
		} else {
			System.out.println("failure");
		}

	}

}











