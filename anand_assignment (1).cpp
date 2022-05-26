#include<bits/stdc++.h>
using namespace std;
class Team{
	private:
		string name;
		int points;
		vector<int> result;
	public:
		Team(string name,vector<int> result){
			this->name = name;
			this->result = result;
			points = 0;
			for(int i=0;i<result.size();i++){
				points += 2*result[i];
			}
		}
		int get_points(){
			return points;
		}
		vector<int> get_result(){
			return result;
		}

};
vector<Team* > team_with_consecutive_result(vector<Team> &points_table,int consecutive = 2,bool win = true){
	
	// returns pointer to team object having : parameter consecutive : parameter (win/loose)

	vector<Team* > ans;
	if(consecutive>5){
		cout<<"Have details of only last 5 matches. Enter the value less than or equal to 5";
		return ans;
	}
	for(int i=0;i<points_table.size();i++){
		bool curr_team = false;
		vector<int> result = points_table[i].get_result();
		for(int j=0;j+consecutive-1<result.size();j++){
			bool from_this_index = false;
			int k = 0;
			for(k=0;k<consecutive;k++){
				if(win==true and result[k+j]==0){
					break;
				}
			}
			if(k==consecutive){
				curr_team = true;
				break;
			}
		}
		if(curr_team){
			Team *temp = &points_table[i];
			ans.push_back(temp);
		}
	}
	return ans;
}

double average_points(vector<Team*> &v){
	// returns the average points of filtered teams
	double total = 0;
	for(auto it=0;it<v.size();it++){
		total += v[it]->get_points();
	}
	return total/v.size();
}

int main(){
	vector<Team> points_table;

	points_table.push_back(Team("GT",{1,1,0,0,1}));
	points_table.push_back(Team("LSG",{1,0,0,1,1}));
	points_table.push_back(Team("RR",{1,0,1,0,0}));
	points_table.push_back(Team("DC",{1,1,0,1,0}));
	points_table.push_back(Team("RCB",{0,1,1,0,0}));
	points_table.push_back(Team("KKR",{0,1,1,0,1}));
	points_table.push_back(Team("PBKS",{0,1,0,1,0}));
	points_table.push_back(Team("SRH",{1,0,0,0,0}));
	points_table.push_back(Team("CSK",{0,0,1,0,1}));
	points_table.push_back(Team("MI",{0,1,0,1,1}));
	
	vector<Team* > curr = team_with_consecutive_result(points_table,2,true); // second param is no. of consecutive wins
	// third param is true for win and false for loose

	// prints the average point of above filtered team
	cout<<average_points(curr)<<endl;

	
	return 0;
}
