fn main()
{
    let _class_utf8 = String::from("My name");
    let _class_ucs4: Vec<char> = String::from("Salve, Munde, őőő űűű").chars().collect();

    let utf8_string = String::from("Salve, Munde, éé áá őő űű");

    println!("UTF-8 string: {}", utf8_string);
    let bvec: Vec<u8> = utf8_string.bytes().collect();
    println!("UTF-8 as vector of bytes: {:?}", bvec);

    print!("UTF-8 as const char*: ");
    for ch in 0..utf8_string.len() {
        print!("{} ", unsafe {utf8_string.get_unchecked(ch..ch+1)} ); // unprintable characters!
    }
    println!();

    let ucs2_string: Vec<u16> = utf8_string.chars().map(|c| c as u16).collect();
    println!("UCS2 string from std::string: {:?}", ucs2_string);

    println!("UTF-8 length: {}, UCS2 length: {}", utf8_string.len(), ucs2_string.len() );
    println!("Verificarion: UTF-8: {}", String::from_utf16(&ucs2_string).unwrap() );
}