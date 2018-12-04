; Preventing overflow in unsigned integer addition

; (set-option :print-success true)
(set-option :produce-models true)
(set-option :interactive-mode true)

; We are using the theory of bit vectors to model unsigned integers
(set-logic QF_BV)

; Declare a, b, c, m to be 32-bit bit vectors
(declare-fun a() (_ BitVec 32))
(declare-fun b() (_ BitVec 32))
(declare-fun c() (_ BitVec 32))
(declare-fun m() (_ BitVec 32))

; Assign UINT_MAX to m
(assert (= m #xffffffff))

; Declare c to be the result of adding bit vectors a and b
(assert (= c (bvadd a b)))

; Assert the negation of the precondition m - a >= b
(assert (bvuge (bvsub m a) b))

; Assert overflow has occurred i.e. (a > c) or (b > c) where (c = a + b)
(assert (or (bvugt a c) (bvugt b c)))

(check-sat)
(get-model)
