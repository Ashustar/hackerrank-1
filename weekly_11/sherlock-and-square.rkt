#lang racket

(define mod 1000000007)

(define (square x) (* x x))

(define (fast-expmod a n)
  (cond ((= n 0) 1)
        ((even? n) (remainder (square (fast-expmod a (/ n 2))) mod))
        (else (remainder (* a (fast-expmod a (- n 1))) mod))))

(define (cal-ans x) (remainder (+ (fast-expmod 2 (+ x 1)) 2) mod))

(define (solve casenum)
  (cond ((not (= casenum 0))
         (begin
          (printf "~a ~n" (cal-ans (read)))
          (solve (- casenum 1))))))

(let ([T (read)])
  (solve T))