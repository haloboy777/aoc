// read file ../test

// time this script
console.time('script')

const fs = require('fs')
const path = require('path')
// const input = fs.readFileSync(path.join(__dirname, '../test'), 'utf8')
const input = fs.readFileSync(path.join(__dirname, '../input'), 'utf8')

const inputArr = input.split('\n')

const RED = 12
const GREEN = 13
const BLUE = 14

let sum = 0
let powerSum = 0

for (let i = 0; i < inputArr.length; i++) {
  if (!inputArr[i]) continue
  const {
    groups: { day, games },
  } = /Game (?<day>\d+): (?<games>.*)/.exec(inputArr[i])
  // console.log(day, games)

  const gamesArr = games.split(';')
  let redMax = 0
  let greenMax = 0
  let blueMax = 0
  let gamePossible = true

  for (let j = 0; j < gamesArr.length; j++) {
    const game = gamesArr[j]
    if (!game) continue
    // get red
    const red = /(?<red>\d+) red/.exec(game)
    // get green
    const green = /(?<green>\d+) green/.exec(game)
    // get blue
    const blue = /(?<blue>\d+) blue/.exec(game)

    const redNum = red ? parseInt(red.groups.red) : 0
    const greenNum = green ? parseInt(green.groups.green) : 0
    const blueNum = blue ? parseInt(blue.groups.blue) : 0

    if (redNum > RED || greenNum > GREEN || blueNum > BLUE) {
      gamePossible = false
    }
    // update redMax
    if (redNum > redMax) redMax = redNum
    // update greenMax
    if (greenNum > greenMax) greenMax = greenNum
    // update blueMax
    if (blueNum > blueMax) blueMax = blueNum
  }
  if (gamePossible) sum += parseInt(day)
  powerSum += redMax * greenMax * blueMax
}

console.log(sum)
console.log(powerSum)

// end time
console.timeEnd('script')
