from flask import Flask, request, jsonify
import subprocess
import os

app = Flask(__name__)

@app.route('/', methods=['GET'])
def run_executable():
    try:
        # Define the executable path
        executable_path = os.path.join(os.path.dirname(__file__), 'compiler')
        
        # Get the file from the request
        # input_file = request.files.get('file')
        # if input_file is None:
        #     return jsonify({'status': 'error', 'message': 'No file provided'}), 400
        
        # # Save the file to a temporary location
        # input_file_path = os.path.join(os.path.dirname(__file__), 'temp_input.txt')
        # input_file.save(input_file_path)

        input_file_path = os.path.join(os.path.dirname(__file__), '..', 'code.txt')
        
        # Run the executable with the input file
        result = subprocess.run([executable_path, input_file_path], capture_output=True, text=True)
        
        # Remove the temporary file
        # os.remove(input_file_path)
        
        # Check if the execution was successful
        if result.returncode == 0:
            return jsonify({
                'status': 'success',
                'output': result.stdout
            })
        else:
            return jsonify({
                'status': 'error',
                'output': result.stderr
            }), 500
    
    except Exception as e:
        return jsonify({
            'status': 'error',
            'message': str(e)
        }), 500

if __name__ == '__main__':
    app.run(debug=True)
