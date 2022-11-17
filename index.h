const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>

    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>PCSECHS Weather Station</title>

</head>
<body>
    <p>Temperature: {temperature}</p>
    <p>Humidity: {humidity}</p>
    <br>
    <p>Heat Index: {heat-index}</p>
</body>
)=====";
