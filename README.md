# WEEK-4-RECOVER-CS50
this is pset4 recover problem

--------------------------------BRIEF ABOUT PROBLEM---------------------------------

ရည်ရွယ်ချက်   ==>  ပျက်သွားသော jpeg file များကို ပြန်လဲ recover လုပ်ရန်ဖြစ်သည်

Jpeg fileတွေရဲ့ ပထမဆုံး(3) byte ဟာ 0xff, 0xd8, 0xff နဲ့စပြီး လေးခုမြောက် byte ဟာ 0xe0-ef တစ်ခုခုနဲ့စတယ်.
ဓာတ်ပုံရိုက်လိုက်တဲ့အခါမှာ image file တွေဟာ memory card ထဲမှာ အစဉ်လိုက်စီသွားတယ်
Memory card တစ်ခုဟာ 512 byte block တွေနဲ့ စုစည်းထားတယ်လို့ ယူဆပါ

လုပ်ဆောင်ရန်  ==>  Memory card ရဲ့ 512-byte-block တစ်ခုအစချင်းစီမှာ JPEG file ရှိလား စစ်စစ်သွားမယ်
                  မရှိရင် နောက်block ကိုကျော်သွားမယ် 
                  ရှိရင် copy and phase ပြီး new file တွေထဲပြန် recover သွားမယ်
                
 -----------------------------------------------------------------------------------
 
 --------------------------------PSEUDO CODE -----------------------------------
 
 STEP 1 ==> check the command line
            --> (has to be only one argument)
            --> else return 1

STEP 2 ==> defined the needed variable for the program
            ->  open memory card
            ->  new data type BYTE
            ->  buffer array
            ->  jpeg count
            ->  open output file to null
            ->  malloc header filename

STEP 3 ==> loop through till the end of memory card

            --> (check this block start with JPEG) 
                    { 
                        -count the filename with sprintf() 
                        -open the output file
                        -count jpeg
                    }
            --> (else)
                    { continue loop }
                    
            --> (output file != NULL )
                    {
                        -write all the data stored in buffer into output file
                    }
            
STEP 4 ==> close all the file we haved opened      

 -----------------------------------------------------------------------------------
 
 -------------------------KNOWLEDGE------------------------------------------------
 
 (1) fopen(filename,"type");
 
 (2) fread(&to,sizeof(), number per once, from);
 
 (3) sprintf(to,"%i", i);
 
 (4) malloc(i * sizeof(data));
 
 (5) NULL pointer
 
