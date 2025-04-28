class Solution:
    def paran(self, param_comb, comb, n_open, n_close, n, l):
        if l==2*n:
            param_comb.append(comb)
            return
        
        if n_open < n:
            self.paran(param_comb, comb+'(', n_open + 1, n_close, n, l+1)
        if n_close < n_open:
            self.paran(param_comb, comb+')', n_open, n_close + 1, n, l+1)

    def generateParenthesis(self, n: int) -> List[str]:
        param_comb = []
        comb = "("
        self.paran(param_comb, comb, 1, 0, n, 1)
        return param_comb
        