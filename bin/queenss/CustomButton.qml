CustomButtonForm {
    rectangle.gradient: if (buttonColor == "grey"
                                && Colors.currentTheme == Colors.dark) {
                            Colors.darkButtonGradient
                        } else if (buttonColor == "grey"
                                   && Colors.currentTheme == Colors.light) {
                            Colors.lightButtonGradient
                        } else {
                            Colors.greenButtonGradient
                        }
}
