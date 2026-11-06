# A simple Decision Tree structure represented via nested dictionaries
decision_tree = {
    "feature": "age > 60",
    "left": {
        "feature": "chest_pain == True",
        "left": "High Risk",
        "right": "Moderate Risk"
    },
    "right": "Low Risk"
}

def print_tree(node, depth=0):
    indent = "    " * depth

    # Base Case: Reached a leaf node (diagnosis string)
    if not isinstance(node, dict):
        print(f"{indent}-> Prediction: {node}")
        return

    # Recursive Step: Decision node with branches
    print(f"{indent}[Split: {node['feature']}]")
    print_tree(node["left"], depth + 1)
    print_tree(node["right"], depth + 1)

print_tree(decision_tree)