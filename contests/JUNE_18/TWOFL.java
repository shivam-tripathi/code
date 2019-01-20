import java.io.*;
import java.util.*;

class TWOFL {
	int n;
	int m;
	int arr[][];
	boolean visited[][];

	public static void main(String[] args) {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader obj = new BufferedReader(isr);

		n = Interger.parseInt(obj.readLine());
		m = Integer.parseInt(obj.readLine());

		arr = new int[n][m];
		visited = new boolean[n][m];

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				arr[i][j] = Integer.parseInt(obj.readLine());
			}
		}

		dfs();

	}
}