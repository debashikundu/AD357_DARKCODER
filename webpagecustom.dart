import 'package:flutter/material.dart';
import 'package:webview/custom.dart';
import 'package:flutter_webview_plugin/flutter_webview_plugin.dart';

import 'main.dart';

class Webpagecm extends StatefulWidget {
  @override
  _WebpagecmState createState() => _WebpagecmState();
}

class _WebpagecmState extends State<Webpagecm> {
  @override
  Widget build(BuildContext context) {
    return WebviewScaffold(
      appBar: AppBar(
        title: Text(lat +com+ lon),
      ),

      url: "https://location10.herokuapp.com/formapp/"+lon+"/"+lat,
      initialChild: Container(
        child: const Center(
          child: Text("Loading......"),
        ),
      ),
      withJavascript: true,
    );

  }
}
