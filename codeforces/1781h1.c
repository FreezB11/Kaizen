#include <stdio.h>
 
#define N	200
#define M	200
#define MD	998244353
#define V2	499122177
#define INF	0x3f3f3f3f
 
int max(int a, int b) { return a > b ? a : b; }
 
int inv(int a) {
	return a == 1 ? 1 : (long long) inv(a - MD % a) * (MD / a + 1) % MD;
}
 
int pp2[N * M + 1], vp2[N * M + 1], ff[N + 5], gg[N + 5];
 
void init() {
	int i;
 
	pp2[0] = vp2[0] = 1;
	for (i = 1; i <= N * M; i++) {
		pp2[i] = pp2[i - 1] * 2 % MD;
		vp2[i] = (long long) vp2[i - 1] * V2 % MD;
	}
	ff[0] = 0, ff[1] = 1;
	for (i = 2; i <= N + 4; i++)
		ff[i] = (ff[i - 1] + ff[i - 2]) % MD;
	for (i = 1; i <= N + 4; i++)
		gg[i] = inv(ff[i]);
}
 
int contains(int l, int r, int i) {
	return l <= i && i <= r;
}
 
int contains_(int il, int jl, int ir, int jr, int i, int j) {
	return contains(il, ir, i) && contains(jl, jr, j);
}
 
int main() {
	int t;
 
	init();
	scanf("%d", &t);
	while (t--) {
		static int ii[N][M], jj[N][M], kk[N][M];
		int n, m, k, u, d, l, r, a, b, i, j, i_, j_, i1, j1, i2, j2, il1, jl1, ir1, jr1, il2, jl2, ir2, jr2, x, y, ans;
 
		scanf("%d%d%d", &n, &m, &k);
		if (k == 0)
			ans = ((long long) pp2[n * m] - pp2[n * (m - 1)] - pp2[(n - 1) * m] + pp2[(n - 1) * (m - 1)]) % MD;
		else if (k == 1) {
			scanf("%d%d", &i1, &j1), i1--, j1--;
			ans = 0;
			for (u = 0; u < 2; u++)
				for (d = 0; d < 2; d++)
					for (l = 0; l < 2; l++)
						for (r = 0; r < 2; r++)
							for (a = 1; a <= n; a++)
								for (b = 1; b <= m; b++) {
									if (u + d >= a || l + r >= b)
										x = 1;
									else {
										x = pp2[(a - u - d) * (b - l - r)];
										if (contains_(i1 - a + 1 + d, j1 - b + 1 + r, i1 - u, j1 - l, 0, 0)
												&& contains_(i1 - a + 1 + d, j1 - b + 1 + r, i1 - u, j1 - l, n - a, m - b))
											x = (long long) x * (1 - vp2[(n - a + 1) * (m - b + 1)]) % MD;
									}
									ans = (ans + x * ((u + d + l + r) % 2 == 0 ? 1 : -1)) % MD;
								}
		} else {
			scanf("%d%d%d%d", &i1, &j1, &i2, &j2), i1--, j1--, i2--, j2--;
			if (i1 > i2)
				i1 = n - 1 - i1, i2 = n - 1 - i2;
			if (j1 < j2)
				j1 = m - 1 - j1, j2 = m - 1 - j2;
			ans = 0;
			for (u = 0; u < 2; u++)
				for (d = 0; d < 2; d++)
					for (l = 0; l < 2; l++)
						for (r = 0; r < 2; r++)
							for (a = 1; a <= n; a++) {
								y = 1;
								for (b = m; b >= 1; b--) {
									il1 = i1 - a + 1 + d, jl1 = j1 - b + 1 + r, ir1 = i1 - u, jr1 = j1 - l;
									il2 = i2 - a + 1 + d, jl2 = j2 - b + 1 + r, ir2 = i2 - u, jr2 = j2 - l;
									if (y != 0 && (!contains_(il1, jl1, ir1, jr1, 0, 0)
											&& !contains_(il2, jl2, ir2, jr2, 0, 0)
											|| !contains_(il1, jl1, ir1, jr1, 0, m - b)
											&& !contains_(il2, jl2, ir2, jr2, 0, m - b)
											|| !contains_(il1, jl1, ir1, jr1, n - a, 0)
											&& !contains_(il2, jl2, ir2, jr2, n - a, 0)
											|| !contains_(il1, jl1, ir1, jr1, n - a, m - b)
											&& !contains_(il2, jl2, ir2, jr2, n - a, m - b)))
										y = 0;
									if (y != 0) {
										j = jl1 - 1;
										if (j >= 0 && j < m - b)
											for (i = max(il1, 0); i <= ir1 && i <= n - a; i++) {
												y = (long long) y * gg[kk[i][j]] % MD * ff[kk[i][j] - 2] % MD * 2 % MD;
												kk[i][j] -= 2;
											}
										j = m - b;
										for (i = n - a; i >= 0; i--) {
											if (i + i2 - i1 > n - a || j + j2 - j1 < 0) {
												i_ = i, j_ = j;
												kk[i_][j_] = 0;
												if (contains_(il1, jl1, ir1, jr1, i, j))
													kk[i_][j_] += 2, y = (long long) y * V2 % MD;
												if (contains_(il2, jl2, ir2, jr2, i, j))
													kk[i_][j_] += 2, y = (long long) y * V2 % MD;
												y = (long long) y * ff[kk[i_][j_]] % MD;
											} else {
												i_ = ii[i + i2 - i1][j + j2 - j1], j_ = jj[i + i2 - i1][j + j2 - j1];
												y = (long long) y * gg[kk[i_][j_]] % MD;
												if (contains_(il2, jl2, ir2, jr2, i, j))
													kk[i_][j_]++, y = (long long) y * V2 % MD;
												else
													kk[i_][j_]--;
												y = (long long) y * ff[kk[i_][j_]] % MD;
											}
											ii[i][j] = i_, jj[i][j] = j_;
										}
									}
									if (u + d >= a || l + r >= b)
										x = 1;
									else
										x = (long long) pp2[(a - u - d) * (b - l - r)] * (1 - y) % MD;
									ans = (ans + x * ((u + d + l + r) % 2 == 0 ? 1 : -1)) % MD;
								}
							}
		}
		if (ans < 0)
			ans += MD;
		printf("%d\n", ans);
	}
	return 0;
}