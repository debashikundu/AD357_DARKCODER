import 'package:flutter/material.dart';
import 'package:webview/alert.dart';
import 'package:webview/custom.dart';
import 'package:webview/webpagepm.dart';
import 'package:geolocator/geolocator.dart';
import 'dart:convert';
import 'dart:core';

//String objText = '{"Latitude": f, "Longitude": g}';
//String objText = '{f,g}';
//User user = User.fromJson(jsonDecode(objText));

String com = " , ";
String getlat = "";
String getlon = "";
String a2 = "Latitude    : ";
String a1 = "Longitude : ";
String a ="";
String b ="";

var arr = [getlat, getlon];

void main() => runApp(MyApp());

//class User {
//String f = getlat;
//String g = getlon;
//  User(this.f, this.g);
//
//  factory User.fromJson(dynamic json) {
//    return User(json['f'] as String, json['g'] as String);
//  }
//
//  @override
//  String toString() {
//    return '{ ${this.f}, ${this.g} }';
//  }
//}



class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "WebView Demo",
      debugShowCheckedModeBanner: false,
      home: Pre(),
    );
  }
}


class Pre extends StatefulWidget {
  @override
  _PreState createState() => _PreState();
}

class _PreState extends State<Pre> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Flood Detection"),
      ),
      body: Container(
        child: Center(
          child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                RaisedButton(
                  child: Text("Location Based Prediction"),
                  onPressed: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(builder: (context) =>Home()),
                    );
                  },
                  color: Colors.blue,
                  textColor: Colors.white,
//                splashColor: Colors.grey,
                ),

                RaisedButton(
                  child: Text("Alert Based Prediction"),
                  onPressed: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(builder: (context) =>Alert()),
                    );
                  },
                  color: Colors.blue,
                  textColor: Colors.white,
//                splashColor: Colors.grey,
                )

              ]
          )
      )
      )


    );
  }
}




class Home extends StatefulWidget {


  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {

  String _latitude  = "";
  String _longitude  = "";

  void _getCurrentLocation() async{
    final position = await Geolocator().getCurrentPosition(desiredAccuracy: LocationAccuracy.high);
    print(position);

    setState(() {
      _latitude = "${position.latitude}";
      _longitude = "${position.longitude}";
      getlat = _latitude;
      getlon = _longitude;
      a = a1 + _longitude;
      b = a2 + _latitude;
    });



  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Flutter Webview"),
      ),
      body: Container(
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
//              Text(getloc),
              SelectableText(b+"\n"+a ),
//            print(user);
              RaisedButton(
                  onPressed: () {
                    _getCurrentLocation();
                  },
                  color: Colors.green,
                  textColor: Colors.white,
                  child:Text("Find Location")),

              Text("Copy the location after clicking this 'Find Location' button"),

//
              RaisedButton(
                child: Text("WebView"),
                onPressed: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(builder: (context) => Webpage()),
                  );
                },
                color: Colors.blue,
                textColor: Colors.white,
//                splashColor: Colors.grey,
              ),

              Text("For custom location,press the 'CUSTOM LOCATION' button below"),
              RaisedButton(
                child: Text("CUSTOM LOCATION"),
                onPressed: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(builder: (context) =>Customloc()),
                  );
                },
                color: Colors.blue,
                textColor: Colors.white,
//                splashColor: Colors.grey,
              )

            ],
          ),
        ),

      ),
    );
  }
}



