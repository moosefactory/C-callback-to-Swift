//
//  ContentView.swift
//  Shared
//
//  Created by Tristan Leblanc on 12/01/2021.
//

import SwiftUI

struct ContentView: View {
    @ObservedObject var myCLibInterface: MyCLibraryInterface = MyCLibraryInterface.shared
    
    var body: some View {
        VStack {
            Text(myCLibInterface.string).frame(width:150).padding()
            Button("Reset") {
                myCLibInterface.setLibString(string: "C Timer Example")
            }.padding()
            Button("Start Timer") {
                myCLibInterface.startLibTimer()
            }.padding()
            Button("Cancel") {
                myCLibInterface.cancelLibTimer()
            }.padding()
        }.padding(20)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
