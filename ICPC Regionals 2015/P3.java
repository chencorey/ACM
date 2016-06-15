import java.util.Scanner;

public class Roll {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int p = s.nextInt();
		int w = s.nextInt();
		float[][] series = new float[n][p];
		
		//Storing first mean
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				series[i][j] = s.nextFloat();
			}
		}
		float[][] mean = new float[n][p];
		//float[][] sumw = new float[n][p];
		float[][] prod = new float[n][p-1];
		
		float[][] mult = new float[n][p];
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < p; j++) {
				mult[i][j-1] = series[i][0]*series[i][j];
			}
			
		}
		//Storing first window sum
		float[][] firstsum = new float[n][p];
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < p; j++) {
				firstsum[0][j] += series[i][j];
				//prod array
				if(j!=0)
					prod[0][j-1] += series[i][0]*series[i][j];
			}
		}
		
		/*
		for (int i = 1; i < n-w+1; i++) {
			for (int j = 1; j < p; j++) {
				//System.out.println(i+" "+j);
				
			}
		}*/
		/*
		for (int i = 0; i < n-w+1; i++) {
			for (int j = 0; j < p-1; j++) {

				System.out.print(prod[i][j]+" ");
			}
			System.out.println();
		}*/
		for (int i = 0; i < n-w+1; i++) {
			for (int j = 0; j < p; j++) {
				if(i!=0 && j!=0)
					prod[i][j-1] = prod[i-1][j-1] -mult[i-1][j-1] + mult[i+w-1][j-1];
				if(i!=0){
					firstsum[i][j] = firstsum[i-1][j] + series[i+w-1][j] - series[i-1][j];
				}
				mean[i][j] = firstsum[i][j]/w;
			}
		}
		float[] cx = new float[p-1]; //count where cov x>0
		//float xdiff;
		//float pdiff;
		float[] sigma = new float[p-1];
		/*for (int i = 0; i < sigma.length; i++) {
			sigma[i] = 0;
		}*/
		for (int i = 0; i < n-w+1; i++) {
			for (int j = 1; j < p; j++) {
				float tsum = prod[i][j-1] - mean[i][0]*firstsum[i][j] - mean[i][j]*firstsum[i][0] + w*mean[i][0]*mean[i][j];
				if(tsum>0)
					cx[j-1]+=1;
			}
		}
		/*
		for (int k = 0; k < n-w+1; k++) {
			
			for(int i = k; i<k+w; i++){
				xdiff = series[i][0]-mean[k][0];
				for (int j = 1; j < p; j++) {
					pdiff = series[i][j]-mean[k][j];
					sigma[j-1] += (xdiff*pdiff);
				}
			}
			for (int i = 0; i < sigma.length; i++) {
				if(sigma[i]>0)
					cx[i]+=1;
				sigma[i] = 0;
			}
			
		}
		*/
		int sz = n-w+1;
		for (int i = 0; i < cx.length; i++) {
			cx[i] = cx[i]*100/ sz;
			System.out.printf("%.2f",cx[i]);
			System.out.println("%");
		}
		
	}
}
