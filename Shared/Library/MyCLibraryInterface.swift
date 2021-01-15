//
//  MyCLibraryInterface.swift
//  TestC
//
//  Created by Tristan Leblanc on 12/01/2021.
//

import Foundation

class MyCLibraryInterface: ObservableObject {
    @Published var string: String = "C Timer Example"
    
    static let shared = MyCLibraryInterface()
    
    init() {
        setCallBack { stringPtr in
            let newString = CFStringCreateWithCString(kCFAllocatorDefault, stringPtr, kCFStringEncodingASCII) ?? "" as CFString
            DispatchQueue.main.async {
                MyCLibraryInterface.shared.string = newString as String
            }
        }
    }
    
    func setLibString(string: String) {
        string.withCString { stringPointer in
            setString(stringPointer)
        }
    }
    
    func startLibTimer() {
        startTimer()
    }

    func cancelLibTimer() {
        cancelTimer()
    }
}
