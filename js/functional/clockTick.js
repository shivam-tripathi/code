
const oneSecond = () => 1000;
const getCurrentTime = () => new Date();
const clear = () => console.clear();
const log = message => console.log(message);

const getTimeObj = date => ({
    hours: date.getHours(),
    minutes: date.getMinutes(),
    seconds: date.getSeconds(),
});

const appendAMPM = timeObj => ({
    ...timeObj,
    AMPM: (timeObj.hours > 12 ? 'PM':'AM')
});

const convertToCivilianTime = timeObj => ({
    ...timeObj,
    hours: (timeObj.hours > 12) ?
        timeObj.hours-12 :
        timeObj.hours
});

const convertToDoubleDigit = arg => arg < 10 ? '0'+arg.toString() : arg.toString();

// Maps an entire object to a function returning a new object
const transform = target => obj =>
    Object.keys(obj).reduce((prev, key) => {
        prev[key] = target(obj[key]);
        return prev;
    },
    {}
);

const prependZero = timeObj => transform(convertToDoubleDigit)(timeObj);

const formatClock = format => timeObj =>
    format.replace('hh', timeObj.hours)
        .replace('mm', timeObj.minutes)
        .replace('ss', timeObj.seconds)
        .replace('tt', timeObj.AMPM)

// Applies set of functions on an object returning a new object
const composeObj = (...fns) => arg => fns.reduce((prev, fn) => transform(fn)(prev), arg);

// Applies set of functions on a value
const compose = (...fns) => arg => fns.reduce((prev, fn) => fn(prev), arg);

const simulateClock = () =>
    compose(
        getTimeObj,
        appendAMPM,
        convertToCivilianTime,
        prependZero,
        formatClock('hh:mm:ss tt'),
        log
    )(getCurrentTime());

// setInterval(simulateClock, oneSecond());

setInterval(
    compose(
        clear,
        getCurrentTime,
        getTimeObj,
        convertToCivilianTime,
        prependZero,
        formatClock('hh:mm:ss tt'),
        log
    ),
    oneSecond()
);


