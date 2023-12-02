use std::collections::HashMap;
use std::io::BufRead;
use std::{fs::File, io::BufReader};

fn process_line2(str: &mut String, digit_map: &HashMap<&str, &str>) -> u32 {
    let mut digits = vec![];

    for (key, val) in digit_map.iter() {
        *str = str.replace(key, val);
    }

    for c in str.chars() {
        if c.is_digit(10) {
            digits.push(c.to_digit(10).unwrap());
        }
    }

    return if digits.len() > 0 {
        (digits.get(0).unwrap() * 10) + (digits.get(digits.len() - 1).unwrap())
    } else {
        0
    };
}

fn process_line(str: String) -> u32 {
    let mut digits = vec![];
    for c in str.chars() {
        if c.is_digit(10) {
            digits.push(c.to_digit(10).unwrap());
        }
    }
    return if digits.len() > 0 {
        (digits.get(0).unwrap() * 10) + (digits.get(digits.len() - 1).unwrap())
    } else {
        0
    };
}

fn main() {
    let file = File::open("../input").unwrap();
    let reader = BufReader::new(file);
    let digit_map: HashMap<&str, &str> = HashMap::from([
        ("one", "o1e"),
        ("two", "t2o"),
        ("three", "t3e"),
        ("four", "f4r"),
        ("five", "f5e"),
        ("six", "s6x"),
        ("seven", "s7n"),
        ("eight", "e8t"),
        ("nine", "n9e"),
    ]);

    let mut sum = 0;
    for line in reader.lines() {
        sum = sum + process_line(line.unwrap());
        // sum = sum + process_line2(&mut line.unwrap(), &digit_map);
    }

    println!("{}", sum);
}
