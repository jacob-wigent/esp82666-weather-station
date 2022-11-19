const char dashboard_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>

    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@100;300;400;500;700;900&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@48,400,0,0" />

    <title>PCSECHS Weather Station</title>

    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: 'Roboto', Helvetica, sans-serif;
        }

        .background {
            width: 100%;
            height: 100vh;
            object-fit: cover;
            position: absolute;
            top: 0;
            left: 0;
            z-index: -1;
            filter: brightness(0.9) saturate(0.75);
        }

        .container {
            background-color: #fff;
            max-width: 500px;
            width: 85%;
            height: 85vh;
            margin: calc(0.5 * (100vh - 85vh)) auto;
            border-radius: 16px;
            box-shadow: 0 4px 4px rgba(20, 48, 54, 0.5);
            padding: 64px;
            text-align: center;
        }

        .date {
            font-size: 18px;
            color: rgb(112 112, 112);
        }

        .main-info{
            display: flex;
            justify-content: center;
            align-items: center;
            margin: 40px 0 30px 0;
        }

        .main-info > * {
            margin: 0px 16px;
        }

        .temperature
        {
            font-weight: 700;
            font-size: 48px;
        }

        .temperature sup
        {
            font-size: 24px;
            position: relative;
            top: -5px;
        }

        .description {
            font-size: 22px;
            font-weight: 700;
        }

        .icon {
            width: 128px;
        }

        .additional {
            margin: 40px auto;
            width: 80%;
            display: flex;
            justify-content: space-evenly;
        }

        .humidity h4, .index h4 {
            font-weight: 400;
            color: rgb(112 112, 112);
            margin-bottom: 10px;
        }

        .humidity p, .index p {
            font-size: 18px;
        }

    </style>

</head>
<body>
    <img class="background" src="https://jkf-arch.com/wp-content/uploads/2019/08/005-Edited.jpg">

    <div class="container">
        <p class="date">2:00 PM, Fri, Nov 18, 2022</p>
        <div class="main-info">
            <img class="icon" src="https://raw.githubusercontent.com/visualcrossing/WeatherIcons/2de560da89d87de44e3ca2a6593a12c19c8346d3/SVG/3rd%20Set%20-%20Monochrome/partly-cloudy-day.svg">
            <p class="temperature">{temperature}<sup>°F</sup></p>
        </div>
        <p class="description">Partly Cloudy</p>
        <div class="additional">
            <div class="humidity">
                <h4>Humidity</h4>
                <p>{humidity}</p>
            </div>
            <div class="index">
                <h4>Heat Index</h4>
                <p>{heat-index}</p>
            </div>
        </div>
    </div>
</body>
)=====";
