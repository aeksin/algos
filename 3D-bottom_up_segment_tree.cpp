V<V<V<ll>>> tree;
void update(ll x,ll y,ll z,ll c,ll c1){
    x+=c1;
    ll init_x = x;
    y+=c1;
    z+=c1;
    for (;x>=1;x/=2){
        for (ll n_y=y;n_y>=1;n_y/=2){
            for (ll n_z=z;n_z>=1;n_z/=2){
                if (x==init_x && n_y==y && n_z==z){
                    tree[x][n_y][n_z] +=c;
                }
                else if (x==init_x && n_y==y){
                    tree[x][n_y][n_z] = tree[x][n_y][2*n_z] + tree[x][n_y][2*n_z+1];
                }
                else if (x==init_x){
                    tree[x][n_y][n_z] = tree[x][2*n_y][n_z] + tree[x][2*n_y+1][n_z];
                }
                else{
                    tree[x][n_y][n_z] = tree[2*x][n_y][n_z] + tree[2*x+1][n_y][n_z];
                }
            }
        }
    }
}
ll gett(ll lx,ll ly,ll lz,ll rx,ll ry,ll rz,ll c1){
    lx+=c1;
    ly+=c1;
    lz+=c1;
    rx+=c1;
    ry+=c1;
    rz+=c1;
    ll sum=0;
    while (lx<=rx){
        ll new_ly=ly;
        ll new_ry=ry;
        while (new_ly<=new_ry){
            ll new_lz=lz;
            ll new_rz=rz;
            while(new_lz<=new_rz){
                if (lx%2==1){
                    if (new_ly%2==1){
                        if (new_lz%2==1){
                            sum+=tree[lx][new_ly][new_lz];
                        }
                        if (new_rz%2==0){
                            sum+=tree[lx][new_ly][new_rz];
                        }
                    }
                    if (new_ry%2==0){
                        if (new_lz%2==1){
                            sum+=tree[lx][new_ry][new_lz];
                        }
                        if (new_rz%2==0){
                            sum+=tree[lx][new_ry][new_rz];
                        }
                    }
                }
                if (rx%2==0){
                    if (new_ly%2==1){
                        if (new_lz%2==1){
                            sum+=tree[rx][new_ly][new_lz];
                        }
                        if (new_rz%2==0){
                            sum+=tree[rx][new_ly][new_rz];
                        }
                    }
                    if (new_ry%2==0){
                        if (new_lz%2==1){
                            sum+=tree[rx][new_ry][new_lz];
                        }
                        if (new_rz%2==0){
                            sum+=tree[rx][new_ry][new_rz];
                        }
                    }
                }
                new_lz++;
                new_rz--;
                new_lz/=2;
                new_rz/=2;
            }
            new_ly++;
            new_ry--;
            new_ly/=2;
            new_ry/=2;
        }
        lx=lx+1;
        rx=rx-1;
        lx/=2;
        rx/=2;
    }
    return sum;
}
