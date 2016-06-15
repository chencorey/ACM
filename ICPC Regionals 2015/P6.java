import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Classy {
	private static class Person implements Comparable{
		public static int maxm;
		public Person(String name, ArrayList<Integer> status) {
			super();
			this.name = name;
			this.status = status;
		}
		
		String name;
		ArrayList status;
		
		@Override
		public int compareTo(Object o) {
			// TODO Auto-generated method stub
			Person p1 = (Person)o; 
			Person p2 = this;
			ArrayList<Integer> a1 = p1.status;
			ArrayList<Integer> a2 = this.status;
			int i;
			for(i=0; i<maxm; i++){
				if(a1.get(i)<a2.get(i))
					return -1;
				else if(a1.get(i)>a2.get(i))
					return 1;
			}
			{
				if(p1.name.compareTo(p2.name)>0)
					return -1;
				else
					return 1;
			}
		}
	}
	private static class PersonComparator implements Comparator<Person>{

		@Override
		public int compare(Person o1, Person o2) {
			// TODO Auto-generated method stub
			ArrayList<Integer> a1 = o1.status;
			ArrayList<Integer> a2 = o2.status;
			//System.out.println(o1.name+" and " + o2.name);
			//System.out.println(a1);
			//System.out.println(a2);
			int min = a1.size()<a2.size()?a1.size():a2.size();
			int i;
			for(i=0; i<min; i++){
				if(a1.get(i)<a2.get(i))
					return -1;
				else if(a1.get(i)>a2.get(i))
					return 1;
			}
			if(a1.size()==a2.size())
			{
				if(o1.name.compareTo(o2.name)>0)
					return 1;
				else
					return -1;
			}
			if(a1.size()>a2.size()){
				while(i<a1.size()){
					if(a1.get(i)==1)
						return -1;
					else if(a1.get(i)==-1)
						return 1;
				}
			}
			if(a2.size()>a1.size()){
				while(i<a2.size()){
					if(a2.get(i)==1)
						return 1;
					else if(a2.get(i)==-1)
						return -1;
				}
			}
			return 0;
		}
		
	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		HashMap<String, Integer> sdict = new HashMap<>();
		sdict.put("upper", 1);
		sdict.put("lower", -1);
		sdict.put("middle", 0);
		ArrayList<Person> people = new ArrayList<>();
		int max = 0;
		while(s.hasNextLine()){
			//StringTokenizer st = new StringTokenizer(s.nextLine());
			String st = s.nextLine();
			int col = st.indexOf(':');
			String name = st.substring(0, col);
			String scs = st.substring(col + 2, st.length()-6);
			ArrayList<Integer> rev = new ArrayList<>();
			ArrayList<Integer> status = new ArrayList<>();
			StringTokenizer sc = new StringTokenizer(scs, "-");
			while(sc.hasMoreTokens()){
				rev.add(sdict.get(sc.nextToken()));
			}
			for (int i = rev.size()-1; i >=0; i--) {
				status.add(rev.get(i));
			}
			max = max>status.size()?max:status.size();
			people.add(new Person(name, status));
		}
		Person.maxm = max;
		for(Person p: people){
			for (int i = p.status.size(); i < max; i++) {
				p.status.add(0);
			}
		}
		PersonComparator com = new PersonComparator();
		Collections.sort(people);
		for(Person p: people)
			System.out.println(p.name);
	}

}
