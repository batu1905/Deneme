/**

* Fonksiyon 1 - Verilen kelimeyi dizide bulma.

* @param {Array.<string>} data - Harfleri içeren string array. Örn: ["DALN","LIMO","KASA"]

* @param {string} word - Aranacak kelime. Örn: "DAL"

* @returns {Array.<{i: Number, j: Number}>}  - Örn: [ {i: 0, j: 0}, {i: 0, j: 1}, {i: 0, j: 2} ]

* @description Fonksiyondan dönen obje dizisinde konum bilgileri sıralı yer almalıdır.

* 'i' satır numarasını, j ise sutün numarasını temsil etmektedir.

*/

 

var sonuc=[];

function find(data, word) {

    // data = [

    //     'JLEX',

    //     'OMXM',

    //     'FASX',

    //     'ZZZX',

    //     'CCCCC'];

    // data = [

    //     'JXEL',

    //     'OXXM',

    //     'FXSA',

    //     'ZZZX',

    //     'CCCCC'];

console.log(data);

console.log(word);

 

let bulunanlar = [];

bulunanlar=findCustom(word,data,"toRight");

console.log(bulunanlar);

 

//  word[0][2]

//  word[1][0]

 

bulunanlar.forEach(item=>{sonuc.push({i:item.rowIndex,j:item.charIndex})});

  return sonuc;

 

 //   return [ {i: 0, j: 0}, {i: 0, j: 1}, {i: 0, j: 2} ];

}

 

function findCustom(word,data)

{

    let bulunanlar = [];  

    let batuhan=[];

    let lastRowIndex=-1;

    let lastCharIndex=-1;

    for (let wordCharIndex = 0; wordCharIndex < word.length; wordCharIndex++) { //word

    let founded=0;

        if(founded==0){

            // word[i]= [E] LMAS

            for(let rowIndex=0;rowIndex<data.length;rowIndex++){ //data

               

                //data[ii] = DAELM

                    for(let charIndex=0;charIndex<data[rowIndex].length;charIndex++)

                    {

                        if(data[rowIndex][charIndex]==word[wordCharIndex]){

 

                            //Sağa doğru arar ve aynı satırda geriye gitmesini engeller

                            if((lastRowIndex==rowIndex && lastCharIndex-charIndex<=1 && lastCharIndex<=charIndex) || lastCharIndex==-1)

                            {

                                bulunanlar.push({rowIndex,charIndex});

                                founded=1;

                                lastCharIndex=charIndex;

                            }

                            //Sağa doğru arar aşağı geri gitmesine olanak tanır.

                            else if(lastRowIndex<rowIndex && charIndex<=lastCharIndex ){

                                bulunanlar.push({rowIndex,charIndex});

                                founded=1;

                                lastCharIndex=charIndex;

                            }

 

                            else if(lastRowIndex==rowIndex && lastCharIndex>charIndex &&  lastCharIndex-charIndex<=1  ){

                                bulunanlar.push({rowIndex,charIndex});

                                founded=1;

                                lastCharIndex=charIndex;

                            }

                         

                            var key=word[wordCharIndex];

                            batuhan.push({rowIndex,charIndex,key});

 

                            lastRowIndex=rowIndex;  

                        }

 

 

 

                }  

 

               

                if(founded==1)

                break;

 

            }

        }

    }

//console.log(batuhan);

    return bulunanlar;

}

 

 

 

/**

* Fonksiyon 2 - İstenilen kelimeyi diziye ekleme.

* @param {Array.<string>} data - Harfleri içeren string array. Örn: ["   N","LIMO","KASA"]

* @returns {Array.<string>}  - Örn: ["AABF","IKLM","NOPS"]

* @description Boşluklar string içinde ' ' şeklinde bulunmaktadır.

* Verilen örnekte ilk satırda 3 adet boşluk ve sonrasında 'N' harfi bulunmaktadır.

* Boşluklar eşsiz harfler ile doldurulmalıdır.

* Örnek: ["BFPN","LIMO","KASA"]

* Sonrasında bu array alfabetik sıraya göre sıralanmalıdır ve sıralanan array döndürülmelidir.

* Örnek: ["AABF","IKLM","NOPS"]

*/

function getNewData(data) {

    // return [

    //     'JLEL',

    //     'OMXM',

    //     'FXSA',

    //     'ZZZX',

    //     'CCCCC'];

    let newData=[];

var index_=0;

    data.forEach(k=>{

 

let rowChars=k;

            sonuc.forEach(item=>{

               

                if(item.i==index_){

                    rowChars=rowChars.replace(k[item.j],"X");

                }

            });

 

newData.push(rowChars);

index_++;

    });

 

console.log(newData);

    //console.log(data[0][1]);

    // sonuc.forEach(item=>{

    //     console.log(item.i+"--"+item.j);

    //    // data[item.i][item.j]="X";

    //        // data[item.i]=data[item.i][item.j];

    //         //data[item.i]=data[item.i][0];

    //     });

 

        return newData;

 

//data = data[0][0]="X";

//   return [ {i: 0, j: 0}, {i: 0, j: 1}, {i: 0, j: 2} ];       

}

 

export { find, getNewData };