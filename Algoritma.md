# English Version.
## Using a Stack to Evaluate an Expression

We often deal with arithmetic expressions written in what is called infix notation:

         Operand1 op Operand2

We have rules to indicate which operations take precedence over others, and we often use parentheses to override those rules.

It is also quite possible to write arithmetic expressions using postfix notation:

         Operand1 Operand2 op

With postfix notation, it is possible to use a stack to find the overall value of an infix expression by first converting it to postfix notation.

Example: Suppose we have this infix expression Q:

         5 * ( 6 + 2 ) - 12 / 4

The equivalent postfix expression P is:

         5 6 2 + * 12 4 / -

This discussion assumes all our operations are binary operations (2 arguments each). Notice that we also sometimes use unary operations such as ++ or -- or the unary + and -.

We are not including the possibility of array elements in this discussion. (The subscript can be an expression which would have to be evaluated.)

One way to think of an expression is as a list or sequence of items, each of which is a left parenthesis, right parenthesis, argument, or operator. An argument can be a constant or the name of a variable. Presumably it would be necessary at some point to replace each variable with its value.

There are two algorithms involved. One converts an infix expression to postfix form, and the other evaluates a postfix expression. Each uses a stack.

### Transform an infix expression to postfix notation

Suppose Q is an arithmetic expression in infix notation. We will create an equivalent postfix expression P by adding items to on the right of P. The new expression P will not contain any parentheses.

We will use a stack in which each item may be a left parenthesis or the symbol for an operation.

     Start with an empty stack.  We scan Q from left to right. 

     While (we have not reached the end of Q)
        If (an operand is found)
           Add it to P
        End-If
        If (a left parenthesis is found) 
           Push it onto the stack
        End-If
        If (a right parenthesis is found) 
           While (the stack is not empty AND the top item is
                  not a left parenthesis)
              Pop the stack and add the popped value to P
           End-While
           Pop the left parenthesis from the stack and discard it 
        End-If
        If (an operator is found)
           If (the stack is empty or if the top element is a left
               parenthesis)
              Push the operator onto the stack
           Else  
              While (the stack is not empty AND the top of the stack 
                     is not a left parenthesis AND precedence of the                  
                     operator <= precedence of the top of the stack)
                 Pop the stack and add the top value to P
              End-While
              Push the latest operator onto the stack     
           End-If  
        End-If
     End-While
     While (the stack is not empty)
        Pop the stack and add the popped value to P
     End-While

Notes:

    At the end, if there is still a left parenthesis at the top of the stack, or if we find a right parenthesis when the stack is empty, then Q contained unbalanced parentheses and is in error. 

### Evaluate a postfix expression

Suppose P is an arithmetic expression in postfix notation. We will evaluate it using a stack to hold the operands.

     Start with an empty stack.  We scan P from left to right.

     While (we have not reached the end of P)
        If an operand is found
           push it onto the stack
        End-If
        If an operator is found
           Pop the stack and call the value A
           Pop the stack and call the value B
           Evaluate B op A using the operator just found.
           Push the resulting value onto the stack
        End-If
    End-While
    Pop the stack (this is the final value)

Notes:

    At the end, there should be only one element left on the stack.

    This assumes the postfix expression is valid. 

### How can this be implemented?

Work like this is usually done by an assembler, compiler or interpreter. A programmer uses an expression in her or her code, and evaluating it is someone else's problem.

Suppose it is our problem (maybe we are writing an interpreter). The interpreter is reading a line at a time from a file as a string, such as

         A = ((B + C) / 3 - 47 % E) * (F + 8)

The string needs to be parsed--that is, we need to break it up into substrings, each of which is one meaningful part. These substrings are often called tokens. The tokens are separated by spaces, in many cases, but also a token ends if we find a left or right parenthesis or the symbol for an operator. Thus for instance, in the above example, we have "E)", and this consists of two tokens "E" and ")". Bear in mind that the symbol for an operator can be more than one character.

We then have a list of tokens, perhaps in an array or a linked list. Somewhere we will have an Evaluate function which takes such a list as an argument and returns a numeric value. 




# Indonesian Version.

## Menggunakan Stack untuk Mengevaluasi Ekspresi

Kita sering berurusan dengan ekspresi aritmatika yang ditulis dalam apa yang disebut notasi infiks:

         Operand1 op Operand2

Kami memiliki aturan untuk menunjukkan operasi mana yang lebih diutamakan dari yang lain, dan kami sering menggunakan tanda kurung untuk mengesampingkan aturan itu.

Dimungkinkan juga untuk menulis ekspresi aritmatika menggunakan notasi postfix:

         Operand1 Operand2 op

Dengan notasi postfix, dimungkinkan untuk menggunakan stack untuk menemukan nilai keseluruhan ekspresi infiks dengan terlebih dahulu mengubahnya menjadi notasi postfix.

Contoh: Misalkan kita memiliki ekspresi infiks ini T:

         5 * (6 + 2) - 12/4

Ekspresi postfix yang setara adalah:

         5 6 2 + * 12 4 / -

Diskusi ini mengasumsikan semua operasi kami adalah operasi biner (masing-masing 2 argumen). Perhatikan bahwa kami juga terkadang menggunakan operasi unary seperti ++ atau - atau unary + dan -.

Kami tidak menyertakan kemungkinan elemen array dalam diskusi ini. (Subskrip dapat berupa ekspresi yang harus dievaluasi.)

Salah satu cara untuk memikirkan ekspresi adalah sebagai daftar atau urutan item, yang masing-masing adalah tanda kurung kiri, tanda kurung kanan, argumen, atau operator. Argumen bisa berupa konstanta atau nama variabel. Agaknya akan perlu di beberapa titik untuk mengganti setiap variabel dengan nilainya.

Ada dua algoritma yang terlibat. Satu mengubah ekspresi infiks ke bentuk postfix, dan yang lainnya mengevaluasi ekspresi postfix. Masing-masing menggunakan tumpukan.

### Ubah ekspresi infiks menjadi notasi postfix

Misalkan Q adalah ekspresi aritmatika dalam notasi infiks. Kami akan membuat ekspresi postfix P yang setara dengan menambahkan item di sebelah kanan P. Ekspresi baru P tidak akan mengandung tanda kurung.

Kami akan menggunakan tumpukan di mana setiap item dapat menjadi tanda kurung kiri atau simbol untuk operasi.

     Mulai dengan tumpukan kosong. Kami memindai Q dari kiri ke kanan.

     Sementara (kami belum mencapai akhir Q)
        Jika (operan ditemukan)
           Tambahkan ke P
        Berakhir jika
        Jika (tanda kurung kiri ditemukan)
           Dorong ke tumpukan
        Berakhir jika
        Jika (kurung yang tepat ditemukan)
           Sementara (tumpukan tidak kosong DAN item teratas adalah
                  bukan tanda kurung kiri)
              Pop stack dan tambahkan nilai yang muncul ke P.
           End-While
           Lepaskan tanda kurung kiri dari tumpukan dan buang
        Berakhir jika
        Jika (operator ditemukan)
           Jika (tumpukan kosong atau jika elemen atas adalah kiri
               kurung)
              Dorong operator ke tumpukan
           Lain
              Sementara (tumpukan tidak kosong DAN bagian atas tumpukan
                     bukan kurung kiri DAN diutamakan dari
                     operator <= prioritas bagian atas tumpukan)
                 Pop stack dan tambahkan nilai teratas ke P
              End-While
              Dorong operator terbaru ke tumpukan
           Berakhir jika
        Berakhir jika
     End-While
     Sementara (tumpukan tidak kosong)
        Pop stack dan tambahkan nilai yang muncul ke P.
     End-While

Catatan:

    Pada akhirnya, jika masih ada tanda kurung kiri di bagian atas tumpukan, atau jika kita menemukan tanda kurung yang tepat ketika tumpukan kosong, maka Q berisi tanda kurung yang tidak seimbang dan ada kesalahan.

### Mengevaluasi ekspresi postfix

Misalkan P adalah ekspresi aritmatika dalam notasi postfix. Kami akan mengevaluasinya menggunakan tumpukan untuk menahan operan.

     Mulai dengan tumpukan kosong. Kami memindai P dari kiri ke kanan.

     Sementara (kami belum mencapai akhir P)
        Jika operan ditemukan
           dorong ke tumpukan
        Berakhir jika
        Jika operator ditemukan
           Pop stack dan panggil nilai A
           Pop stack dan panggil nilai B
           Evaluasi B op A menggunakan operator yang baru saja ditemukan.
           Dorong nilai yang dihasilkan ke tumpukan
        Berakhir jika
    End-While
    Pop the stack (ini adalah nilai akhir)

Catatan:

    Pada akhirnya, hanya ada satu elemen yang tersisa di tumpukan.

    Ini mengasumsikan ekspresi postfix valid.

### Bagaimana ini bisa diterapkan?

Pekerjaan seperti ini biasanya dilakukan oleh assembler, compiler atau interpreter. Seorang programmer menggunakan ekspresi dalam kodenya, dan mengevaluasinya adalah masalah orang lain.

Misalkan itu adalah masalah kita (mungkin kita sedang menulis penerjemah). Penerjemah membaca satu baris pada satu waktu dari sebuah file sebagai string, seperti

         A = ((B + C) / 3 - 47% E) * (F + 8)

String harus diurai - yaitu, kita perlu memecahnya menjadi substring, yang masing-masing merupakan satu bagian yang bermakna. Substring ini sering disebut token. Token dipisahkan oleh spasi, dalam banyak kasus, tetapi juga token berakhir jika kita menemukan tanda kurung kiri atau kanan atau simbol untuk operator. Jadi misalnya, dalam contoh di atas, kita memiliki "E)", dan ini terdiri dari dua token "E" dan ")". Ingatlah bahwa simbol untuk operator dapat lebih dari satu karakter.

Kami kemudian memiliki daftar token, mungkin dalam array atau daftar yang ditautkan. Di suatu tempat kita akan memiliki fungsi Evaluasi yang mengambil daftar seperti itu sebagai argumen dan mengembalikan nilai numerik.
