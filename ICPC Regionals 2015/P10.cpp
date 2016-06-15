#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int s;
char board[20000][20000];

bool isblack(char c)
{
	if(c>='a' && c<='z') return true;
	return false;
}

bool iswhite(char c)
{
	if(c>='A' && c<='Z') return true;
	return false;
}

bool ispawn(char c)
{
	if(c=='p' || c=='P') return true;
	return false;
}

bool isknight(char c)
{
	if(c=='n' || c=='N') return true;
	return false; 
}

bool isking(char c)
{
	if(c=='k' || c=='K') return true;
	return false;
}

bool isqueen(char c)
{
	if(c=='q' || c=='Q') return true;
	return false;
}

bool isbishop(char c)
{
	if(c=='b' || c=='B') return true;
	return false;
}

bool isrook(char c)
{
	if(c=='r' || c=='R') return true;
	return false;
}

bool isvalid(int r,int c)
{
	if(r>=1 && r<=s && c>=1 && c<=s) return true;
	return false;
}

bool whitedanger(int r,int c)
{
	int counter;
	//pawns
	if(isvalid(r+1,c-1) && isblack(board[r+1][c-1]) && ispawn(board[r+1][c-1])) return true;
	if(isvalid(r+1,c+1) && isblack(board[r+1][c+1]) && ispawn(board[r+1][c+1])) return true;
	
	//knights
	if(isvalid(r+2,c-1) && isblack(board[r+2][c-1]) && isknight(board[r+2][c-1])) return true;
	if(isvalid(r+2,c+1) && isblack(board[r+2][c+1]) && isknight(board[r+2][c+1])) return true;
	if(isvalid(r-2,c-1) && isblack(board[r-2][c-1]) && isknight(board[r-2][c-1])) return true;
	if(isvalid(r-2,c+1) && isblack(board[r-2][c+1]) && isknight(board[r-2][c+1])) return true;
	
	if(isvalid(r+1,c-2) && isblack(board[r+1][c-2]) && isknight(board[r+1][c-2])) return true;
	if(isvalid(r+1,c+2) && isblack(board[r+1][c+2]) && isknight(board[r+1][c+2])) return true;
	if(isvalid(r-1,c-2) && isblack(board[r-1][c-2]) && isknight(board[r-1][c-2])) return true;
	if(isvalid(r-1,c+2) && isblack(board[r-1][c+2]) && isknight(board[r-1][c+2])) return true;
	
	//kings
	if(isvalid(r+1,c-1) && isblack(board[r+1][c-1]) && isking(board[r+1][c-1])) return true;
	if(isvalid(r+1,c) && isblack(board[r+1][c]) && isking(board[r+1][c])) return true;
	if(isvalid(r+1,c+1) && isblack(board[r+1][c+1]) && isking(board[r+1][c+1])) return true;
	if(isvalid(r-1,c-1) && isblack(board[r-1][c-1]) && isking(board[r-1][c-1])) return true;
	if(isvalid(r-1,c) && isblack(board[r-1][c]) && isking(board[r-1][c])) return true;
	if(isvalid(r-1,c+1) && isblack(board[r-1][c+1]) && isking(board[r-1][c+1])) return true;
	if(isvalid(r,c-1) && isblack(board[r][c-1]) && isking(board[r][c-1])) return true;
	if(isvalid(r,c+1) && isblack(board[r][c+1]) && isking(board[r][c+1])) return true;
	
	//rooks
	 counter=1;
	while(isvalid(r,c+counter))
	{
		if(iswhite(board[r][c+counter])) break;
		if(isblack(board[r][c+counter]) && !isrook(board[r][c+counter]) && !isqueen(board[r][c+counter])) break;
 		if(isblack(board[r][c+counter]) && (isrook(board[r][c+counter]) || isqueen(board[r][c+counter])) ) return true;
		counter++;
	}
	 counter=1;
	while(isvalid(r,c-counter))
	{
		if(iswhite(board[r][c-counter])) break;
		if(isblack(board[r][c-counter]) && !isrook(board[r][c-counter]) && !isqueen(board[r][c-counter])) break;
		if(isblack(board[r][c-counter]) && (isrook(board[r][c-counter]) || isqueen(board[r][c-counter])) ) return true;
		counter++;
	}
	 counter=1;
	while(isvalid(r+counter,c))
	{
		if(iswhite(board[r+counter][c])) break;
		if(isblack(board[r+counter][c]) && !isrook(board[r+counter][c]) && !isqueen(board[r+counter][c])) break;
		if(isblack(board[r+counter][c]) && (isrook(board[r+counter][c]) || isqueen(board[r+counter][c])) ) return true;
		counter++;
	}
	 counter=1;
	while(isvalid(r-counter,c))
	{
		if(iswhite(board[r-counter][c])) break;
		if(isblack(board[r-counter][c]) && !isrook(board[r-counter][c]) && !isqueen(board[r-counter][c])) break;
		if(isblack(board[r-counter][c]) && (isrook(board[r-counter][c]) || isqueen(board[r-counter][c])) ) return true;
		counter++;
	}
	
	//bishops
	 counter=1;
	while(isvalid(r+counter,c+counter))
	{
		if(iswhite(board[r+counter][c+counter])) break;
		if(isblack(board[r+counter][c+counter]) && !isbishop(board[r+counter][c+counter]) && !isqueen(board[r+counter][c+counter])) break;
		if(isblack(board[r+counter][c+counter]) && (isbishop(board[r+counter][c+counter]) || isqueen(board[r+counter][c+counter]))) return true;
		counter++; 
	}
	 counter=1;
	while(isvalid(r+counter,c-counter))
	{
		if(iswhite(board[r+counter][c-counter])) break;
		if(isblack(board[r+counter][c-counter]) && !isbishop(board[r+counter][c-counter]) && !isqueen(board[r+counter][c-counter])) break;
		if(isblack(board[r+counter][c-counter]) && (isbishop(board[r+counter][c-counter]) || isqueen(board[r+counter][c-counter]))) return true;
		counter++; 
	}
	 counter=1;
	while(isvalid(r-counter,c+counter))
	{
		if(iswhite(board[r-counter][c+counter])) break;
		if(isblack(board[r-counter][c+counter]) && !isbishop(board[r-counter][c+counter]) && !isqueen(board[r-counter][c+counter])) break;
		if(isblack(board[r-counter][c+counter]) && (isbishop(board[r-counter][c+counter]) || isqueen(board[r-counter][c+counter]))) return true;
		counter++; 
	}
	 counter=1;
	while(isvalid(r-counter,c-counter))
	{
		if(iswhite(board[r-counter][c-counter])) break;
		if(isblack(board[r-counter][c-counter]) && !isbishop(board[r-counter][c-counter]) && !isqueen(board[r-counter][c-counter])) break;
		if(isblack(board[r-counter][c-counter]) && (isbishop(board[r-counter][c-counter]) || isqueen(board[r-counter][c-counter]))) return true;
		counter++; 
	}
	
	return false;
}

bool blackdanger(int r,int c)
{
	int counter;
	//pawns
	if(isvalid(r-1,c-1) && iswhite(board[r-1][c-1]) && ispawn(board[r-1][c-1])) return true;
	if(isvalid(r-1,c+1) && iswhite(board[r-1][c+1]) && ispawn(board[r-1][c+1])) return true;
	
	//knights
	if(isvalid(r+2,c-1) && iswhite(board[r+2][c-1]) && isknight(board[r+2][c-1])) return true;
	if(isvalid(r+2,c+1) && iswhite(board[r+2][c+1]) && isknight(board[r+2][c+1])) return true;
	if(isvalid(r-2,c-1) && iswhite(board[r-2][c-1]) && isknight(board[r-2][c-1])) return true;
	if(isvalid(r-2,c+1) && iswhite(board[r-2][c+1]) && isknight(board[r-2][c+1])) return true;
	
	if(isvalid(r+1,c-2) && iswhite(board[r+1][c-2]) && isknight(board[r+1][c-2])) return true;
	if(isvalid(r+1,c+2) && iswhite(board[r+1][c+2]) && isknight(board[r+1][c+2])) return true;
	if(isvalid(r-1,c-2) && iswhite(board[r-1][c-2]) && isknight(board[r-1][c-2])) return true;
	if(isvalid(r-1,c+2) && iswhite(board[r-1][c+2]) && isknight(board[r-1][c+2])) return true;
	
	//kings
	if(isvalid(r+1,c-1) && iswhite(board[r+1][c-1]) && isking(board[r+1][c-1])) return true;
	if(isvalid(r+1,c) && iswhite(board[r+1][c]) && isking(board[r+1][c])) return true;
	if(isvalid(r+1,c+1) && iswhite(board[r+1][c+1]) && isking(board[r+1][c+1])) return true;
	if(isvalid(r-1,c-1) && iswhite(board[r-1][c-1]) && isking(board[r-1][c-1])) return true;
	if(isvalid(r-1,c) && iswhite(board[r-1][c]) && isking(board[r-1][c])) return true;
	if(isvalid(r-1,c+1) && iswhite(board[r-1][c+1]) && isking(board[r-1][c+1])) return true;
	if(isvalid(r,c-1) && iswhite(board[r][c-1]) && isking(board[r][c-1])) return true;
	if(isvalid(r,c+1) && iswhite(board[r][c+1]) && isking(board[r][c+1])) return true;
	
	//rooks
	counter=1;
	while(isvalid(r,c+counter))
	{
		if(isblack(board[r][c+counter])) break;
		if(iswhite(board[r][c+counter]) && !isrook(board[r][c+counter]) && !isqueen(board[r][c+counter])) break;
		if(iswhite(board[r][c+counter]) && (isrook(board[r][c+counter]) || isqueen(board[r][c+counter])) ) return true;
		counter++;
	}
	counter=1;
	while(isvalid(r,c-counter))
	{
		if(isblack(board[r][c-counter])) break;
		if(iswhite(board[r][c-counter]) && !isrook(board[r][c-counter]) && !isqueen(board[r][c-counter])) break;
		if(iswhite(board[r][c-counter]) && (isrook(board[r][c-counter]) || isqueen(board[r][c-counter])) ) return true;
		counter++;
	}
	counter=1;
	while(isvalid(r+counter,c))
	{
		if(isblack(board[r+counter][c])) break;
		if(iswhite(board[r+counter][c]) && !isrook(board[r+counter][c]) && !isqueen(board[r+counter][c])) break;
		if(iswhite(board[r+counter][c]) && (isrook(board[r+counter][c]) || isqueen(board[r+counter][c])) ) return true;
		counter++;
	}
	counter=1;
	while(isvalid(r-counter,c))
	{
		if(isblack(board[r-counter][c])) break;
		if(iswhite(board[r-counter][c]) && !isrook(board[r-counter][c]) && !isqueen(board[r-counter][c])) break;
		if(iswhite(board[r-counter][c]) && (isrook(board[r-counter][c]) || isqueen(board[r-counter][c])) ) return true;
		counter++;
	}
	
	//bishops
	 counter=1;
	while(isvalid(r+counter,c+counter))
	{
		if(isblack(board[r+counter][c+counter])) break;
		if(iswhite(board[r+counter][c+counter]) && !isbishop(board[r+counter][c+counter]) && !isqueen(board[r+counter][c+counter])) break;
		if(iswhite(board[r+counter][c+counter]) && (isbishop(board[r+counter][c+counter]) || isqueen(board[r+counter][c+counter]))) return true;
		counter++; 
	}
	 counter=1;
	while(isvalid(r+counter,c-counter))
	{
		if(isblack(board[r+counter][c-counter])) break;
		if(iswhite(board[r+counter][c-counter]) && !isbishop(board[r+counter][c-counter]) && !isqueen(board[r+counter][c-counter])) break;
		if(iswhite(board[r+counter][c-counter]) && (isbishop(board[r+counter][c-counter]) || isqueen(board[r+counter][c-counter]))) return true;
		counter++; 
	}
	 counter=1;
	while(isvalid(r-counter,c+counter))
	{
		if(isblack(board[r-counter][c+counter])) break;
		if(iswhite(board[r-counter][c+counter]) && !isbishop(board[r-counter][c+counter]) && !isqueen(board[r-counter][c+counter])) break;
		if(iswhite(board[r-counter][c+counter]) && (isbishop(board[r-counter][c+counter]) || isqueen(board[r-counter][c+counter]))) return true;
		counter++; 
	}
	 counter=1;
	while(isvalid(r-counter,c-counter))
	{
		if(isblack(board[r-counter][c-counter])) break;
		if(iswhite(board[r-counter][c-counter]) && !isbishop(board[r-counter][c-counter]) && !isqueen(board[r-counter][c-counter])) break;
		if(iswhite(board[r-counter][c-counter]) && (isbishop(board[r-counter][c-counter]) || isqueen(board[r-counter][c-counter]))) return true;
		counter++; 
	}
	
	return false;
}

int main()
{
	int n;
	cin>>s>>n;
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=s;j++)
		{
			board[i][j]='.';
		}
	}
	char targetcolor,targetpiece;
	int targetr,targetc;
	cin>>targetcolor>>targetpiece>>targetr>>targetc;
	n--;
	while(n--)
	{
		char color,piece;
		int r,c;
		cin>>color>>piece>>r>>c;
		if(color=='W')
		{
			board[r][c]=toupper(piece);
		}
		else
		{
			board[r][c]=tolower(piece);
		}
	}
	if(targetcolor=='W') 
	{
		if(whitedanger(targetr,targetc)) cout<<"In Danger"<<endl;
		else cout<<"Not in Danger"<<endl;
	}
	else
	{
		if(blackdanger(targetr,targetc)) cout<<"In Danger"<<endl;
		else cout<<"Not in Danger"<<endl;
	}
	return 0;
}
