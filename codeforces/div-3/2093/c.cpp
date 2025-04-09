#includ
}

bool isPrime(long long x){
  if(x <= n){
    return prim[x];
  }
  for(long long i = 2; i * i <= x; i++){
    if(x % i == 0){
      return false;
    }
  }
  return true;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  int tc; cin >> tc;
  while(tc--){
    int x, k; cin >> x >> k;
    if(k == 2 && x == 1){
      cout << "YES"<< endl;
      continue;
    }
    if(k > 1 && x > 1){
      cout << "NO" << endl;
    }else if(k == 1 && isPrime(x)){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}
