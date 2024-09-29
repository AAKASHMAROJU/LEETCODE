// Link: https://leetcode.com/problems/encode-and-decode-tinyurl

/**
 * Encodes a URL to a shortened URL.
 *
 * @param {string} longUrl
 * @return {string}
 */

var gen_str=""
for(let i=0;i<10;i++){
    gen_str+=String(i);
}
var enc_mp={};
for(let i=0;i<26;i++){
    gen_str+=String.fromCharCode(i+65);
    gen_str+=String.fromCharCode(i+97);
}



var encode = function(longUrl) {
    var enc_str="";
    do{
        enc_str="";
        for(let i=0;i<6;i++){
            enc_str+=gen_str[Math.floor(Math.random() * 62)];
        }
    }while(enc_str in enc_mp);
    enc_mp[enc_str]=longUrl;
    return "http://tinyurl.com/"+enc_str;
};

/**
 * Decodes a shortened URL to its original URL.
 *
 * @param {string} shortUrl
 * @return {string}
 */
var decode = function(shortUrl) {
    let m=shortUrl.length;
    let s="";
    for(let i=m-1;i>=0;i--){
        if(shortUrl[i]=='/') break;
        s=shortUrl[i]+s;
    }
    return enc_mp[s];
};

/**
 * Your functions will be called as such:
 * decode(encode(url));
 */
